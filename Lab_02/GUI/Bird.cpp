#include "Bird.h"
#include "HelperMath.h"

void SetBird(Model& bird)
{
	//туловище
	float bBody = 75;
	float aBody = 150;
	Ellipse_t bodyEllipse(2 * bBody, 2 * aBody, Vector2D(0, 0), 0);
	Polygon_t bodyPolygon = bodyEllipse.GetPolygon();
	bird.polygons.push_back(bodyPolygon);

	//голова
	// точка соприкосновения эллипса и головы
	float r = 25;
	int i = 350;
	
	Vector2D centerHead = GetCenteCircleTangentToEllipse(aBody, bBody, r, bodyPolygon.points[i]);

	Ellipse_t HeadEllipse(2 * r, 2 * r, centerHead, 0, 0xFF0FFF);
	Polygon_t HeadPolygon = HeadEllipse.GetPolygon();
	bird.polygons.push_back(HeadPolygon);


	//нос
	std::vector<Vector2D> noise;
	noise.push_back(Vector2D(centerHead.x - 10, centerHead.y + 1));
	noise.push_back(Vector2D(centerHead.x - 10, centerHead.y + 16));
	noise.push_back(Vector2D(centerHead.x - 70, centerHead.y + 1));
	bird.polygons.push_back(Polygon_t(noise, 0xFF00000));


	//левая нога ноги
	std::vector<Vector2D> leftLeg;
	Vector2D leftLegBody = bodyPolygon.points[594];
	leftLeg.push_back(leftLegBody);
	leftLeg.push_back(Vector2D(leftLegBody.x - 30, leftLegBody.y - 60));
	bird.polygons.push_back(Polygon_t(leftLeg, 0xFF8C00));

	//правая нога
	std::vector<Vector2D> rightLeg;
	Vector2D rightLegBody = bodyPolygon.points[621];
	rightLeg.push_back(rightLegBody);
	rightLeg.push_back(Vector2D(rightLegBody.x + 10, rightLegBody.y - 50));
	bird.polygons.push_back(Polygon_t(rightLeg, 0xFF8C00));

	//крыло
	std::vector<Vector2D> wing;
	wing.push_back(Vector2D(10, -10));
	wing.push_back(Vector2D(60, -10));
	wing.push_back(Vector2D(100, -125));
	wing.push_back(Vector2D(90, -120));
	wing.push_back(Vector2D(80, -110));
	bird.polygons.push_back(Polygon_t(wing, 0x0000000));

	//хвост
	std::vector<Vector2D> tail;
	tail.push_back(Vector2D(aBody - 20, 20));
	tail.push_back(Vector2D(aBody + 50, 20));
	tail.push_back(Vector2D(aBody - 20, -10));
	bird.polygons.push_back(Polygon_t(tail, 0x0000000));
}
