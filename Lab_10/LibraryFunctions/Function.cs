using System;

namespace LibraryFunctions
{
    public class Function
    {
        public Function(string name, Func<double, double, double> funcY)
        {
            Name = name;
            FuncY = funcY;
        }

        public string Name { get; private set; }
        public Func<double, double, double> FuncY { get; private set; }

        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
                return false;

            return (obj as Function).Name == Name;
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode();
        }
    }
}
