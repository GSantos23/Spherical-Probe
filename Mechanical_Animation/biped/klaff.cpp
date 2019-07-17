/*
	Klann Mechanism animation using Gnuplot-Iostream
	Author: Gerson Santos
	Date: August 5th 2015
*/

/* 
 g++ -o klaff klaff.cpp -lboost_iostreams -lboost_system -lboost_filesystem
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include "gnuplot-iostream.h"
#include <boost/tuple/tuple.hpp>

using namespace std;

int main()
{
	Gnuplot gp;
	double const pi = 3.141592653589793;
	double const step = 3;
	int index=0;
	string num;
	// Declarcion de Vectores
	// ******************************* Extremidad Derecha
	vector<vector<double> > points(11,vector<double>(2)); 
	vector<vector<double> > verde(2,vector<double>(2)); 
	vector<vector<double> > azul(2,vector<double>(2)); 
	//****************************** Extremidad Izquierda
	vector<vector<double> > rojo(10,vector<double>(2));
	vector<vector<double> > verde2(2,vector<double>(2)); 
	vector<vector<double> > azul2(2,vector<double>(2)); 
    //***********************************************************
	vector<vector<double> > traject(360/step, vector<double>(2));
	double iter = 0;
	// Eslabones
	double L0(0), L1(0), L2(0), L3(0), L4(0), L5(0), L6(0), L7(0);
	// Angulos principales Derecha
    double th0(0), th1(0), th2(0), th3(0), th4(0), th5(0), th6(0), th7(0), th8(0), th9(0), th22(0);
    // Angulos principales Izquierda
    double th1_2(0), th2_2(0), th3_2(0), th4_2(0), th5_2(0), th6_2(0), th7_2(0), th8_2(0), th9_2(0);
    // Variables Vectores Derecha
	vector<double> a(2), b(2), c(2), d(2), e(2), f(2), g(2), h(2), i(2), j(2), k(2), l(2);
	vector<double> b2(2), d2(2), f3(2), g3(2);
	// Variables de Vectores Izquierda
	vector<double> aa(2), bb(2), cc(2), dd(2), ee(2), ff(2), gg(2), hh(2), ii(2), jj(2), kk(2), ll(2);
	vector<double> b4(2), d4(2), f5(2), g5(2);
	// Variables Virtuales
	double R1(0), R2(0), R3(0), R4(0);
	// Angulo internos de eslabones derecha
	double alfa(0), betta(0), gamma(0), delta(0), epsilon(0);
	// Angulo internos de eslabones izquierda
	double alfa2(0), betta2(0), gamma2(0), delta2(0), epsilon2(0);
	// Componentes de nodos extremidad derecha
	double ax(0), ay(0), bx(30), by(-12), cx(0), cy(0), fx(0), fy(0), fx2(0), fy2(0), dx(25), dy(11.50), ex(0), ey(0), zx(0), zy(0), gx(0), gy(0);
	// Componentes de nodos extremidad izquierda
	double a2x(0), a2y(0), b2x(-30), b2y(-12),c2x(0),c2y(0), f3x(0), f3y(0), f4x(0), f4y(0), d2x(-25), d2y(11.50), e2x(0), e2y(0), z2x(0), z2y(0), g2x(0), g2y(0);
	//*********************************************************************** Constantes
	L1 = 13.00;			L2 = 20.00;			    L3 = 30.00; 
	L4 = 26.00;	        L5 = 25.00;			    L6 = 30.00; 
	L7 = 32.00;
	//***************** Declaracion de vectores extremidad derecha
	vector<double> ax_vec;
	vector<double> ay_vec;
	vector<double> cx_vec;
	vector<double> cy_vec;	
	vector<double> fx_vec;
	vector<double> fy_vec;	
	vector<double> fx2_vec;
	vector<double> fy2_vec;
	vector<double> ex_vec;
	vector<double> ey_vec;	
	vector<double> zx_vec;
	vector<double> zy_vec;
	vector<double> gx_vec;
	vector<double> gy_vec;
	//***************** Declaracion de vectores extremidad izquierda
	vector<double> a2x_vec;
	vector<double> a2y_vec;
	vector<double> c2x_vec;
	vector<double> c2y_vec;	
	vector<double> f3x_vec;
	vector<double> f3y_vec;
	vector<double> f4x_vec;
	vector<double> f4y_vec;
	vector<double> e2x_vec;
	vector<double> e2y_vec;
	vector<double> z2x_vec;
	vector<double> z2y_vec;
	vector<double> g2x_vec;
	vector<double> g2y_vec;
	//***********************************************************
	
	while(iter < 360)
	{
		index++;
		stringstream stream;
		stream << index;
		num = stream.str();
		
		if (iter==360)
		{
			iter = 0;			
		}
		th0 = iter; // radians

		th0 *= (pi/180); // deg -> rad
		
		cout << th0 << endl;
		
	//****************************************************************
	// Eslabon L1 
		ax = L1*cos(th0);							/**/	a2x = L1*cos(th0 + pi);
		ay = L1*sin(th0);							/**/	a2y = L1*sin(th0 + pi);
		
		ax_vec.push_back(ax);						/**/	a2x_vec.push_back(a2x);
		ay_vec.push_back(ay);						/**/	a2y_vec.push_back(a2y);	

		R1 = sqrt(pow(ax-bx,2) + pow(ay-by,2));	/**/	R3 = sqrt(pow(a2x - b2x,2) + pow(a2y - b2y,2));				
		
	// Angulo alfa		
		alfa = atan2((ay - by),(ax - bx));				/**/	alfa2 = atan2((a2y - b2y),(a2x - b2x));						

	// Angulo Beta (Ley de Cosenos)
		betta = acos((R1*R1+L2*L2 -L3*L3)/(2*R1*L2));	/**/    betta2 = acos((R3*R3+L2*L2 -L3*L3)/(2*R3*L2));   			
		
	// Angulo phi1
	// /_ Dado que el angulo se toma de esta manera no restamos PI ******************************************************************
		th1 = alfa - betta;								/**/    th1_2 = alfa2 + betta2 + pi;	
		
	// Nodo C
		cx = bx + L2*cos(th1);							/**/    c2x = b2x - L2*cos(th1_2);			
		cy = by + L2*sin(th1);							/**/    c2y = b2y - L2*sin(th1_2);			
		
		cx_vec.push_back(cx);							/**/    c2x_vec.push_back(c2x);	
		cy_vec.push_back(cy);							/**/	c2y_vec.push_back(c2y);	
		
		th2 = atan2((cy-ay),(cx-ax));					/**/    th2_2 = atan2((c2y-a2y),(c2x-a2x));	

	// Nodo F  
		fx =  L3*cos(th2) + L1*cos(th0);				/**/	 f3x = L3*cos(th2_2) + L1*cos(th0 + pi);
		fy =  L3*sin(th2) + L1*sin(th0); 				/**/	 f3y = L3*sin(th2_2) + L1*sin(th0 + pi);	
		
		fx_vec.push_back(fx);							/**/	 f3x_vec.push_back(f3x);			
		fy_vec.push_back(fy);							/**/	 f3y_vec.push_back(f3y);	

	// Nodo F2 
		fx2 = L4*cos(th2) + L3*cos(th2) + L1*cos(th0);	/**/	f4x = L4*cos(th2_2) + L3*cos(th2_2) + L1*cos(th0 + pi);		
		fy2 = L4*sin(th2) + L3*sin(th2) + L1*sin(th0);  /**/	f4y = L4*sin(th2_2) + L3*sin(th2_2) + L1*sin(th0 + pi);		
		
		fx2_vec.push_back(fx2);							/**/    f4x_vec.push_back(f4x);			
		fy2_vec.push_back(fy2);							/**/	f4y_vec.push_back(f4y);
		
	// Variable Virtual
		R2 = sqrt(pow(fx2-dx,2) + pow(fy2-dy,2));      /**/     R4 = sqrt(pow(f4x-d2x,2) + pow(f4y-d2y,2));
		
	// Angulo gamma
		gamma = atan2((fy2-dy),(fx2-dx)) ;		      /**/     gamma2 = atan2((f4y-d2y),(f4x-d2x));
		
	// Angulo delta
		delta = acos((R2*R2 + L6*L6 - L5*L5)/(2*R2*L6));       delta2 = acos((R4*R4 + L6*L6 - L5*L5)/(2*R4*L6));
		
	// Angulo phi4
		th4 = gamma - delta - pi;					 /**/      th4_2 = gamma2 + delta2 + pi;
				
	// Nodo e												
		ex = ax + (L3 + L4)*cos(th2) + L6*cos(th4);    /**/    e2x = a2x + (L3 + L4)*cos(th2_2) + L6*cos(th4_2); 
		ey = ay + (L3 + L4)*sin(th2) + L6*sin(th4);    /**/    e2y = a2y + (L3 + L4)*sin(th2_2) + L6*sin(th4_2);

		ex_vec.push_back(ex);							/**/   e2x_vec.push_back(e2x);
		ey_vec.push_back(ey);							/**/   e2y_vec.push_back(e2y);
		
	// Angulo phi3
		th3 = atan2((ey-dy),(ex-dx));					/**/   th3_2 = atan2((e2y-d2y),(e2x-d2x));
		
		zx = L4*cos(th3) + dx; 							/**/   z2x = L4*cos(th3_2) + dx;
		zy = L4*sin(th3) + dy; 							/**/   z2y = L4*sin(th3_2) + dy;
		
		zx_vec.push_back(zx);							/**/   z2x_vec.push_back(z2x);
		zy_vec.push_back(zy);							/**/   z2y_vec.push_back(z2y);
		
	// Angulo para eslabon de efector final
		epsilon = acos((L4*L4 + L5*L5 - R2*R2)/(2*L4*L5));
		
		th5 = th4 - 30*pi/180;						    /**/   th5_2 =  th4_2 + 30*pi/180;
        // 275*pi/180 + gamma;									// 275*pi/180 + gamma2;
		
	// Nodo G
		gx = -L7*cos(th5) + (L3 + L4)*cos(th2) + ax;    /**/   g2x = -L7*cos(th5_2) + (L3 + L4)*cos(th2_2) + a2x; 
		gy = -L7*sin(th5) + (L3 + L4)*sin(th2) + ay;    /**/   g2y = -L7*sin(th5_2) + (L3 + L4)*sin(th2_2) + a2y; 

		gx_vec.push_back(gx);							/**/	   g2x_vec.push_back(g2x);
		gy_vec.push_back(gy);							/**/       g2y_vec.push_back(g2y);

	//************************************************************************************	
	// Grafica los eslabones en gnuplot
		a[0] = 0;							/**/	aa[0] = 0;	 
		a[1] = 0;							/**/	aa[1] = 0;
		c[0] = L1*cos(th0);					/**/    cc[0] = L1*cos(th0 + pi);
		c[1] = L1*sin(th0);					/**/    cc[1] = L1*sin(th0 + pi);
		d[0] = c[0] + L3*cos(th2);			/**/    dd[0] = cc[0] + L3*cos(th2_2);
		d[1] = c[1] + L3*sin(th2);			/**/	dd[1] =	cc[1] + L3*sin(th2_2);
		e[0] = d[0] + L4*cos(th2);			/**/    ee[0] = dd[0] + L4*cos(th2_2);
		e[1] = d[1] + L4*sin(th2);			/**/    ee[1] = dd[1] + L4*sin(th2_2);
		f[0] = e[0] + L6*cos(th4);			/**/    ff[0] = ee[0] + L6*cos(th4_2);
		f[1] = e[1] + L6*sin(th4);			/**/    ff[1] = ee[1] + L6*sin(th4_2);
		g[0] = e[0] - L7*cos(th5);			/**/	gg[0] = ee[0] - L7*cos(th5_2);
		g[1] = e[1] - L7*sin(th5);			/**/    gg[1] = ee[1] - L7*sin(th5_2);
		
	// Siempre tiene que hacer un punto de retorno a->c , c->a

		points[0] = a; 						/**/  rojo[0] = aa;
		points[1] = c; 						/**/  rojo[1] = cc;
		points[2] = d; 						/**/  rojo[2] = dd;
		points[3] = e;						/**/  rojo[3] = ee;
		points[4] = f;						/**/  rojo[4] = ff;
		points[5] = e;						/**/  rojo[5] = ee;
		points[6] = g;						/**/  rojo[6] = gg;
		points[7] = e;						/**/  rojo[7] = ee;
		points[8] = d;						/**/  rojo[8] = dd;
		points[9] = c;						/**/  rojo[9] = cc;
		points[10] = a;						/**/

	//************************************************************************************
	//  Esta seccion fija y grafica en eslabon L2

		b2[0] = 30;							/**/	b4[0] = -30;
		b2[1] = -12;						/**/    b4[1] = -12;
		d2[0] = b2[0] + L2*cos(th1);		/**/	d4[0] = b4[0] - L2*cos(th1_2);
		d2[1] = b2[1] + L2*sin(th1); 		/**/	d4[1] = b4[1] - L2*sin(th1_2);
		
		verde[0] = b2;						/**/	verde2[0] = b4;
		verde[1] = d2;						/**/	verde2[1] = d4;

	//************************************************************************************ 
	// Esta seccion fija  y grafica en eslabon L5 

		f3[0] = 25;							/**/	f5[0] = -25;
		f3[1] = 11.50;						/**/    f5[1] = 11.50;
		g3[0] = f3[0] + L5*cos(th3);		/**/	g5[0] = f5[0] + L5*cos(th3_2);
		g3[1] = f3[1] + L5*sin(th3);		/**/	g5[1] = f5[1] + L5*sin(th3_2);

		
		azul[0] = f3; 						/**/	azul2[0] = f5;
		azul[1] = g3;						/**/    azul2[1] = g5;

	//***********************************************************************************

		gp << "set terminal pngcairo size 1000,900 \n";
		gp << "set output '" << num << ".png' \n";
		gp << "set grid \n";
		gp << "set size square \n";
		gp << "set encoding iso_8859_1 \n";
		//gp << "set key font 'Times New Roman,18' \n ";
		//gp << "set key spacing 1.25 \n";
		gp << "set key off \n";
		gp << "set xtics font 'Times New Roman,16' \n";
		gp << "set ytics font 'Times New Roman,16' \n";
		gp << "set xlabel font 'Times New Roman,18' \n";
		gp << "set ylabel font 'Times New Roman,18' \n";
		gp << "set xlabel offset -3 \n";
		gp << "set ylabel offset -3 \n";
		gp << "set xlabel 'X(cm)' \n";
		gp << "set ylabel 'Y(cm)' \n";
		gp << "set xrange[-90:90] \n";
		gp << "set yrange[-90:90] \n";
		gp << "set pointsize 2 \n";
		gp << "plot '-' u 1:2 w lp lw 5 t 'Mecanismo', '-' u 1:2 w lp lw 5 t 'Mecanismo2', '-' u 1:2 w lp lw 5 t 'Mecanismo3', \
		       '-' u 1:2 w lp lc 1 lw 5 , '-' u 1:2 w lp lc 2 lw 5, '-' u 1:2 w lp lc 3 lw 5,\
		       '-' t 'Nodo A' w l lc 1 lw 3, '-' t 'Nodo C' w l lc 2 lw 3 , '-' t 'Nodo F' w l lc 3 lw 3, '-' t 'Nodo F2' w l lc 4 lw 3,\
		       '-' t 'Nodo E' w l lc 5 lw 3, '-' t 'Nodo G' w l lc 6 lw 3, '-' t 'Nodo G2' w  l lc 7 lw 3\n";
		gp.send1d(points);
		gp.send1d(verde);
		gp.send1d(azul);
		gp.send1d(rojo);
		gp.send1d(verde2);
		gp.send1d(azul2);
		gp.send1d(boost::make_tuple(ax_vec,ay_vec)); // Grafica Trayectoria L1
		gp.send1d(boost::make_tuple(cx_vec,cy_vec)); // Grafica Trayectoria L2
		gp.send1d(boost::make_tuple(fx_vec,fy_vec)); // Grafica Trayectoria L3
		gp.send1d(boost::make_tuple(fx2_vec,fy2_vec)); // Grafica Trayectoria L4
		gp.send1d(boost::make_tuple(ex_vec,ey_vec)); // Grafica Trayectoria 
		gp.send1d(boost::make_tuple(gx_vec,gy_vec)); // Grafica Trayectoria Efector Final
		gp.send1d(boost::make_tuple(g2x_vec,g2y_vec));
		iter+=step;						
	}
	
	return 0;
}
