/**
* @file PassThroughFilterTest.cpp
* @Author Muhammet Eren S�ME (erensome1@gmail.com)
* @date December, 2021
* @brief Bu kod PassThroughFilter sinifini test eder.
*/
#include"PassThroughFilter.h"
#include<iostream>
using namespace std;

//! PassThroughFilter sinifini test eden fonksiyon.
//! @see main.cpp
void PassThroughFilterTest()
{
	cout << "--------------------------" << endl;
	cout << "|Pass Through Filter Test|" << endl;
	cout << "--------------------------" << endl;

	//Degerli set et.
	PassThroughFilter ptf1;
	ptf1.setLLX(0); // X 0'in alt�ndaysa ��kar
	ptf1.setULX(6); // X 6'nin �st�ndeyse ��kar
	ptf1.setLLY(1); // Y 1'in �st�ndeyse ��kar
	ptf1.setULY(4); // Y 4'un �st�ndeyse ��kar
	ptf1.setLLZ(2); // Z 2'n�n �st�ndeyse ��kar
	ptf1.setULZ(7); // Z 7'n�n �st�ndeyse ��kar

	cout << "Lower Limit for (X,Y,Z) = (" << ptf1.getLLX() << ", " << ptf1.getLLY() << ", " << ptf1.getLLZ() << ")" << endl;
	cout << "Upper Limit for (X,Y,Z) = (" << ptf1.getULX() << ", " << ptf1.getULY() << ", " << ptf1.getULZ() << ")" << endl << endl;
	//0,1,2
	//6,4,7
	
	//Pointleri olustur.
	Point p1, p2, p3, p4, p5, p6, p7;
	p1.SetPoint(0, 4, 5);
	p2.SetPoint(8, 3, 5); // X uymuyor.
	p3.SetPoint(4, 0, 9); // Y ve Z uymuyor.
	p4.SetPoint(7, 5, 1); // X, Y ve Z uymuyor.
	p5.SetPoint(5.35, -1, 3.12); // Y uymuyor.
	p6.SetPoint(6, 2, -5.32); // Z uymuyor.
	p7.SetPoint(5, 3, 6.78);

	//Pointleri PointCloud icine koy.
	PointCloud pc;
	pc.InsertPoints(p1);
	pc.InsertPoints(p2);
	pc.InsertPoints(p3);
	pc.InsertPoints(p4);
	pc.InsertPoints(p5);
	pc.InsertPoints(p6);
	pc.InsertPoints(p7);

	//Filtreleme isleminden once PointCloud icindeki Point uye sayisini ve Pointleri yazdir.
	list<Point>::iterator it;
	list<Point> listOfPC;
	listOfPC = pc.GetPoints();
	cout << "Number of points before filtering: " << pc.GetPointNumber() << endl;
	Point temp;
	for (it = listOfPC.begin(); it != listOfPC.end(); it++)
	{
		cout << "Element's points: (X,Y,Z) = (" << it->getX() << ", " << it->getY() << ", " << it->getZ() << ")" << endl;
	}
	cout << endl;

	//Filtreleme islemi.
	ptf1.filter(pc);

	listOfPC = pc.GetPoints();
	//Filtreleme isleminden sonra PointCloud icindeki Point uye sayisini ve Pointleri yazdir.
	cout << "Number of points after filtering: " << pc.GetPointNumber() << endl;
	for (it = listOfPC.begin(); it != listOfPC.end(); it++)
	{
		cout << "Element's points: (X,Y,Z) = (" << it->getX() << ", " << it->getY() << ", " << it->getZ() << ")" << endl;
	}
	cout << endl;
}