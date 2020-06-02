using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows;

namespace GUI
{
    class Cutter : ICutter
    {
        public Cutter()
        {
            points = new List<Point>();
        }

        private List<Point> points;
        public List<Point> Points
        {
            get => points;
            set => SetPoints(value);
        }

        public Vector[] Normals { get; private set; }

        public PointF[] Cut(PointF A, PointF B)
        {
            float tDown = 0, tUp = 1;
            float tTemp;

            Vector D = new Vector(A, B);
            Vector W;

            float DScalar, WScalar;

            for (int i = 0; i < Points.Count; i++)
            {
                W = new Vector(Points[i], A);

                DScalar = Vector.Scalar(D, Normals[i]);
                WScalar = Vector.Scalar(W, Normals[i]);

                if (DScalar == 0) // отрезок выродился в точку или отрезок паралелен 
                {
                    if (WScalar < 0)
                        return null;
                    // иначе точка видима относительно текущей границы
                }
                else
                {
                    tTemp = -WScalar / DScalar;
                    if (DScalar > 0) // поиск нижнего предела
                    {
                        if (tTemp > 1)
                            return null;
                        tDown = Math.Max(tDown, tTemp);
                    }
                    else // поиск верхнего предела
                    {
                        if (tTemp < 0)
                            return null;
                        tUp = Math.Min(tUp, tTemp);
                    }
                }

                if (tDown > tUp)
                    return null;
            }


            var newA = new PointF(A.X + D.X * tDown, A.Y + D.Y * tDown);
            var newB = new PointF(A.X + D.X * tUp, A.Y + D.Y * tUp);

            return new PointF[2] { newA, newB };
        }

        public List<PointF> Cut(List<Point> polygon)
        {
            List<PointF> cuttedPolygon = new List<PointF>();
            foreach (var points in polygon)
                cuttedPolygon.Add(points);
            cuttedPolygon.Add(cuttedPolygon.First());

            List<PointF> tempPolygon = new List<PointF>();

            PointF? I;
            // по всем сторонам отсекателя
            for (int i = 0; i < Points.Count(); i++)
            {
                // по всем сторонам многоугольника
                for (int j = 1; j < cuttedPolygon.Count(); j++)
                {
                    I = GetPointIntersection(cuttedPolygon[j - 1], cuttedPolygon[j], i);
                    if (I.HasValue)
                        tempPolygon.Add(I.Value);

                    if (IsVisible(cuttedPolygon[j], i))
                        tempPolygon.Add(cuttedPolygon[j]);
                }

                if (tempPolygon.Count() == 0)
                    return null;

                I = GetPointIntersection(cuttedPolygon.First(), cuttedPolygon.Last(), i);
                if (I.HasValue)
                    tempPolygon.Add(I.Value);

                tempPolygon.Add(tempPolygon.First());
                cuttedPolygon.Clear();
                cuttedPolygon.AddRange(tempPolygon);
                tempPolygon.Clear();
            }
            return cuttedPolygon;
        }

        private bool IsVisible(PointF point, int i)
        {
            var W = new Vector(Points[i], point);
            var WScalar = Vector.Scalar(W, Normals[i]);
            return WScalar >= 0;
        }

        private PointF? GetPointIntersection(PointF V0, PointF V1, int i)
        {
            // директриса текущего отрезка
            Vector D = new Vector(V0, V1);
            var DScalar = Vector.Scalar(D, Normals[i]);

            if (DScalar != 0) // Провека, что не точка и не парралельно
            {
                var W = new Vector(Points[i], V0);
                var WScalar = Vector.Scalar(W, Normals[i]);
                float t = -WScalar / DScalar;
                if (t >= 0 && t <= 1)  // заменить проверку на проверку знаков видимости точек
                {
                    PointF I = new PointF();
                    I.X = V0.X + D.X * t;
                    I.Y = V0.Y + D.Y * t;
                    return I;
                }
            }

            return null;
        }

        // если мн-к не выпуклый будет брошено исключение NoConvexCutterException
        private void SetPoints(List<Point> points)
        {
            int direction = ManagerMath.GetRoundDirection(points);
            if (direction == 0)
                throw new NoConvexCutterException();

            Normals = ManagerMath.GetNormals(points, direction);
            this.points = points;
        }
    }
}
