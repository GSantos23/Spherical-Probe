/*
 3D Klann Mechanism animation using Gnuplot-Iostream
 
 Author: Gerson Santos
 Date: August 5th 2015
*/

/*
 
 g++ -o klaffy klaffy.cpp -lboost_iostreams -lboost_system -lboost_filesystem

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
	// *************************************************************************************************** Extremidad Derecha Frontral
	vector<vector<double> > points(11,vector<double>(3)); //3 debido a que son 3 ejes: xyz
	vector<vector<double> > verde(2,vector<double>(3)); 
	vector<vector<double> > azul(2,vector<double>(3)); 
	//**************************************************************************************************** Extremidad Izquierda Frontral
	vector<vector<double> > rojo(11,vector<double>(3));
	vector<vector<double> > verde2(2,vector<double>(3)); 
	vector<vector<double> > azul2(2,vector<double>(3)); 
	
	//************************************************************************************************* Extremidad Derecha Trasera
	vector<vector<double> > circle(11,vector<double>(3)); 
	vector<vector<double> > verde3(2,vector<double>(3)); 
	vector<vector<double> > azul3(2,vector<double>(3)); 
	
	//************************************************************************************************* Extremidad Izquierda Trasera
	
	vector<vector<double> > rojo4(11,vector<double>(3)); 
	vector<vector<double> > verde4(2,vector<double>(3)); 
	vector<vector<double> > azul4(2,vector<double>(3)); 
	
	//*******************************************************************************************************************************************
	vector<vector<double> > traject(360/step, vector<double>(3)); //2
	double iter = 0;
	// Eslabones
	double L0(0), L1(0), L2(0), L3(0), L4(0), L5(0), L6(0), L7(0);
	// Angulos principales Derecha
    double th0(0), th1(0), th2(0), th3(0), th4(0), th5(0);
    // Angulos principales Izquierda
    double th1_2(0), th2_2(0), th3_2(0), th4_2(0), th5_2(0);
    // Angulos principales Izquierda
    double th1_3(0), th2_3(0), th3_3(0), th4_3(0), th5_3(0);
    
        // Angulos principales Izquierda
    double th1_4(0), th2_4(0), th3_4(0), th4_4(0), th5_4(0);
    // Variables Vectores Derecha
	vector<double> a(3), b(3), c(3), d(3), e(3), f(3), g(3);
	vector<double> b2(3), d2(3), f3(3), g3(3);
	// Variables de Vectores Izquierda
	vector<double> aa(3), bb(3), cc(3), dd(3), ee(3), ff(3), gg(3);
	vector<double> b4(3), d4(3), f5(3), g5(3);
	// Variables de Vectores Izquierda Frontal(izf)
	vector<double> ifa(3), ifb(3), ifc(3), ifd(3), ife(3);
	vector<double> iff(3), ifg(3), ifh(3), ifj(3), ifk(3);
	
	// Variables de Vectores Derecha Trasera(dt)
	vector<double> dta(3), dtb(3), dtc(3), dtd(3), dte(3);
	vector<double> dtf(3), dtg(3), dth(3), dtj(3), dtk(3);
	
	// Variables de Vectores Izquierda Trasera(it)
	vector<double> ita(3), itb(3), itc(3), itd(3), ite(3);
	vector<double> itf(3), itg(3), ith(3), itj(3), itk(3);
	
	// Variables Virtuales Frontales
	double R1(0), R2(0), R3(0), R4(0);
	// Variable Virtuales Traseras
	double R5(0),R6(0),R7(0),R8(0);
	// Angulo internos de eslabones derecha
	double alfa(0), betta(0), gamma(0), delta(0), epsilon(0);
	// Angulo internos de eslabones izquierda
	double alfa2(0), betta2(0), gamma2(0), delta2(0), epsilon2(0);
	// Angulos internos Extremidad Derecha Trasera
	double alfa3(0), betta3(0), gamma3(0), delta3(0), epsilon3(0);
	
		// Angulos internos Extremidad Izquierda Trasera
	double alfa4(0), betta4(0), gamma4(0), delta4(0), epsilon4(0);
	
	// Componentes de nodos Extremidad Derecha Frontal
	double ax(0), ay(0),az(0), bx(30), by(-15), cx(0), cy(0), cz(0), fx(0), fy(0), fz(0);
	double fx2(0), fy2(0), fz2(0), dx(25), dy(11.50), ex(0), ey(0), ez(0), gx(0), gy(0), gz(0);
	// Componentes de nodos Extremidad Izquierda Frontal
	double a2x(0), a2y(0),a2z(0), b2x(-30), b2y(-15), c2x(0), c2y(0), c2z(0), d2x(-25), d2y(11.50);
	double f3x(0), f3y(0), f3z(0), f4x(0), f4y(0), f4z(0), e2x(0), e2y(0), e2z(0), g2x(0), g2y(0), g2z(0);
	// Componentes de nodos Extremidad Derecha Trasera
	double a3x(0), a3y(0),a3z(0), b3x(30), b3y(-15), c3x(0), c3y(0), c3z(0), f5x(0), f5y(0), f5z(0); 
	double f6x(0),f6y(0),f6z(0), d3x(25), d3y(11.50), e3x(0),e3y(0),e3z(0), g3x(0), g3y(0),g3z(0);
	
	// Componentes de nodos Extremidad Derecha Trasera
	double a4x(0), a4y(0),a4z(0), b4x(-30), b4y(-15), c4x(0), c4y(0), c4z(0), f7x(0), f7y(0), f7z(0); 
	double f8x(0),f8y(0),f8z(0), d4x(-25), d4y(11.50), e4x(0),e4y(0),e4z(0), g4x(0), g4y(0),g4z(0);
	
	bool trj = false;
	bool gsm = true;
	bool lcj = true;
	//*********************************************************************** Constantes
	L1 = 13.00;			L2 = 20.00;			    L3 = 30.00; 
	L4 = 26.00;	        L5 = 25.00;			    L6 = 30.00; 
	L7 = 32.00;

	//***************************************************************** Declaracion de vectores extremidad derecha e izquierda
	vector<double> ax_vec;				/**/		vector<double> a2x_vec;
	vector<double> ay_vec;				/**/		vector<double> a2y_vec;
	vector<double> az_vec;				/**/		vector<double> a2z_vec;
	vector<double> cx_vec;				/**/		vector<double> c2x_vec;
	vector<double> cy_vec;				/**/		vector<double> c2y_vec;
	vector<double> cz_vec;				/**/		vector<double> c2z_vec;
	vector<double> fx_vec;				/**/        vector<double> f3x_vec;
	vector<double> fy_vec;				/**/		vector<double> f3y_vec;
	vector<double> fz_vec;				/**/		vector<double> f3z_vec;
	vector<double> fx2_vec;				/**/		vector<double> f4x_vec;
	vector<double> fy2_vec;				/**/		vector<double> f4y_vec;
	vector<double> fz2_vec;				/**/        vector<double> f4z_vec;
	vector<double> ex_vec;				/**/		vector<double> e2x_vec;
	vector<double> ey_vec;				/**/		vector<double> e2y_vec;
	vector<double> ez_vec;				/**/		vector<double> e2z_vec;
	vector<double> gx_vec;				/**/		vector<double> g2x_vec;
	vector<double> gy_vec;				/**/		vector<double> g2y_vec;
	vector<double> gz_vec;				/**/		vector<double> g2z_vec;
	
	//**************************************************************** Declaracion de vectores extremidad izquierda

	vector<double> a3x_vec;				/**/		vector<double> a4x_vec;	
	vector<double> a3y_vec;				/**/		vector<double> a4y_vec;	
	vector<double> a3z_vec;				/**/		vector<double> a4z_vec;	
	vector<double> c3x_vec;				/**/		vector<double> c4x_vec;	
	vector<double> c3y_vec;				/**/		vector<double> c4y_vec;	
	vector<double> c3z_vec;				/**/		vector<double> c4z_vec;	
	vector<double> f5x_vec;				/**/		vector<double> f7x_vec;
	vector<double> f5y_vec;				/**/		vector<double> f7y_vec;
	vector<double> f5z_vec;				/**/		vector<double> f7z_vec;
	vector<double> f6x_vec;				/**/		vector<double> f8x_vec;
	vector<double> f6y_vec;				/**/		vector<double> f8y_vec;
	vector<double> f6z_vec;				/**/		vector<double> f8z_vec;
	vector<double> e3x_vec;				/**/		vector<double> e4x_vec;
	vector<double> e3y_vec;				/**/		vector<double> e4y_vec;
	vector<double> e3z_vec;				/**/		vector<double> e4z_vec;
	vector<double> g3x_vec;				/**/		vector<double> g4x_vec;	
	vector<double> g3y_vec;				/**/		vector<double> g4y_vec;	
	vector<double> g3z_vec;				/**/		vector<double> g4z_vec;	


	while(lcj = true) //iter < 360, lcj = true
	{
		index++;
		stringstream stream;
		stream << index;
		num = stream.str();
		
		if (iter==360)
		{
			iter = 0;
			trj = true;			
		}
		th0 = iter; // radians

		th0 *= (-pi/180); // deg -> rad
		
		cout << th0 << endl;
		
	//*****************************************************************************************************************************		
	// Eslabon L1 
		ax = L1*cos(th0);								/**/		a3x = L1*cos(th0 - pi);
		ay = L1*sin(th0);								/**/		a3y = L1*sin(th0 - pi);
		az= 60;                                         /**/        a3z = -60;
		ax_vec.push_back(ax);							/**/		a3x_vec.push_back(a3x);
		ay_vec.push_back(ay);							/**/		a3y_vec.push_back(a3y);	
        az_vec.push_back(az);							/**/        a3z_vec.push_back(a3z);
        
    //-----------------------------------------------------------------------------------------------------------------------------
        
        a2x = L1*cos(th0 + pi);							/**/		a4x = L1*cos(th0);		
		a2y = L1*sin(th0 + pi);							/**/		a4y = L1*sin(th0);
		a2z= 60;                                        /**/ 		a4z= -60;        
		a2x_vec.push_back(a2x);							/**/		a4x_vec.push_back(a4x);		
		a2y_vec.push_back(a2y);							/**/		a4y_vec.push_back(a4y);
        a2z_vec.push_back(a2z);							/**/        a4z_vec.push_back(a4z);
        
        
	// Variable Virtual
        R1 = sqrt(pow(ax-bx,2) + pow(ay-by,2));			/**/		R5 = sqrt(pow(a3x-b3x,2) + pow(a3y-b3y,2));	
        R3 = sqrt(pow(a2x-b2x,2) + pow(a2y-b2y,2));		/**/ 		R7 = sqrt(pow(a4x-b4x,2) + pow(a4y-b4y,2));	
        
    // Angulo alfa		
		alfa = atan2((ay - by),(ax - bx));				/**/		alfa3 = atan2((a3y - b3y),(a3x - b3x));	
		alfa2 = atan2((a2y - b2y),(a2x - b2x));			/**/		alfa4 = atan2((a4y - b4y),(a4x - b4x));	
		
	// Angulo Beta (Ley de Cosenos)
		betta = acos((R1*R1+L2*L2 -L3*L3)/(2*R1*L2));	/**/		betta3 = acos((R5*R5+L2*L2 -L3*L3)/(2*R5*L2));
		betta2 = acos((R3*R3+L2*L2 -L3*L3)/(2*R3*L2));  /**/ 		betta4 = acos((R7*R7+L2*L2 -L3*L3)/(2*R7*L2));
		
	// Angulo phi1
	// /_ Dado que el angulo se toma de esta manera no restamos PI ******************************************************************
		th1 = alfa - betta;											th1_3 = alfa3 - betta3;	
		//th1_2 = alfa2 + betta2 + pi;	
		
	// Nodo C
		cx = bx + L2*cos(th1);                          /**/		c3x = b3x + L2*cos(th1_3);
		cy = by + L2*sin(th1);							/**/		c3y = b3y + L2*sin(th1_3);
		cz = 60;										/**/		c3z = -60;
		
		cx_vec.push_back(cx);							/**/		c3x_vec.push_back(c3x);
		cy_vec.push_back(cy);							/**/		c3y_vec.push_back(c3y);
		cz_vec.push_back(cz);							/**/		c3z_vec.push_back(c3z);
		// ------------------------------------------------------------------------------------------------
		th1_2 = alfa2 + betta2 + pi;								th1_4 = alfa4 + betta4 + pi;
		c2x = b2x - L2*cos(th1_2);						/**/		c4x = b4x - L2*cos(th1_4);
		c2y = b2y - L2*sin(th1_2);						/**/		c4y = b4y - L2*sin(th1_4);	
		c2z = 60;										/**/		c4z = -60;
		
		c2x_vec.push_back(c2x);							/**/		c4x_vec.push_back(c4x);
		c2y_vec.push_back(c2y);							/**/		c4y_vec.push_back(c4y);	
		c2z_vec.push_back(c2z);							/**/		c4z_vec.push_back(c4z);
		
				
		th2 = atan2((cy-ay),(cx-ax));					/**/		th2_3 = atan2((c3y-a3y),(c3x-a3x));
		th2_2 = atan2((c2y-a2y),(c2x-a2x));				/**/		th2_4 = atan2((c4y-a4y),(c4x-a4x));	
		
	// Nodo F ************************************************************************************************************************* 
		fx =  L3*cos(th2) + L1*cos(th0);				/**/		f5x = L3*cos(th2_3) + L1*cos(th0 - pi);
		fy =  L3*sin(th2) + L1*sin(th0);				/**/		f5y = L3*sin(th2_3) + L1*sin(th0 - pi);
		fz =  60;										/**/		f5z = -60;
		
		fx_vec.push_back(fx);							/**/		f5x_vec.push_back(f5x);		
		fy_vec.push_back(fy);							/**/		f5y_vec.push_back(f5y);
		fz_vec.push_back(fz);							/**/		f5z_vec.push_back(f5z);
	//--------------------------------------------------------------------------------------------------------------------------------
		f3x = L3*cos(th2_2) + L1*cos(th0 + pi);						f7x = L3*cos(th2_4) + L1*cos(th0 );			
		f3y = L3*sin(th2_2) + L1*sin(th0 + pi);						f7y = L3*sin(th2_4) + L1*sin(th0 );
		f3z = 60;													f7z = -60;
		
		f3x_vec.push_back(f3x);										f7x_vec.push_back(f7x);
		f3y_vec.push_back(f3y);										f7y_vec.push_back(f7y);
		f3z_vec.push_back(f3z);										f7z_vec.push_back(f7z);

	// Nodo F2 ************************************************************************************************************************
		fx2 = L4*cos(th2) + L3*cos(th2) + L1*cos(th0);				f6x = L4*cos(th2_3) + L3*cos(th2_3) + L1*cos(th0-pi);
		fy2 = L4*sin(th2) + L3*sin(th2) + L1*sin(th0);				f6y = L4*sin(th2_3) + L3*sin(th2_3) + L1*sin(th0-pi);
		fz2 = 60;													f6z = -60;
		
		fx2_vec.push_back(fx2);										f6x_vec.push_back(f6x);
		fy2_vec.push_back(fy2);										f6y_vec.push_back(f6y);
		fz2_vec.push_back(fz2);										f6z_vec.push_back(f6z);
	//----------------------------------------------------------------------------------------------------------------------------------
		f4x = L4*cos(th2_2) + L3*cos(th2_2) + L1*cos(th0 + pi);		f8x = L4*cos(th2_4) + L3*cos(th2_4) + L1*cos(th0);
		f4y = L4*sin(th2_2) + L3*sin(th2_2) + L1*sin(th0 + pi);		f8y = L4*sin(th2_4) + L3*sin(th2_4) + L1*sin(th0);
		f4z = 60;													f8z = -60;
		
		f4x_vec.push_back(f4x);										f8x_vec.push_back(f8x);	
		f4y_vec.push_back(f4y);										f8y_vec.push_back(f8y);	
		f4z_vec.push_back(f4z);										f8z_vec.push_back(f8z);	
	
	//*************************************************************************************************************** Termina Hoekens : OK 
	//*************************************************************************************************************** Empieza Klann	  : OK

	// Variable Virtual
		R2 = sqrt(pow(fx2-dx,2) + pow(fy2-dy,2)); 					R6 = sqrt(pow(f6x-d3x,2) + pow(f6y-d3y,2)); 
		R4 = sqrt(pow(f4x-d2x,2) + pow(f4y-d2y,2));	 				R8 = sqrt(pow(f8x-d4x,2) + pow(f8y-d4y,2));
		
	// Angulo gamma
		gamma = atan2((fy2-dy),(fx2-dx));						    gamma3 = atan2((f6y-d3y),(f6x-d3x));
		gamma2 = atan2((f4y-d2y),(f4x-d2x));						gamma4 = atan2((f8y-d4y),(f8x-d4x));
		
	// Angulo delta
		delta = acos((R2*R2 + L6*L6 - L5*L5)/(2*R2*L6)); 			delta3 = acos((R6*R6 + L6*L6 - L5*L5)/(2*R6*L6));
		delta2 = acos((R4*R4 + L6*L6 - L5*L5)/(2*R4*L6));			delta4 = acos((R8*R8 + L6*L6 - L5*L5)/(2*R8*L6));
		
	// Angulo phi4
		th4 = gamma - delta - pi;									th4_3 = gamma3 - delta3 - pi; 
		th4_2 = gamma2 + delta2 + pi;								th4_4 = gamma4 + delta4 + pi;
		
	// Nodo e												
		ex = ax + (L3 + L4)*cos(th2) + L6*cos(th4);				/**/ e3x = a3x + (L3 + L4)*cos(th2_3) + L6*cos(th4_3);
		ey = ay + (L3 + L4)*sin(th2) + L6*sin(th4);				/**/ e3y = a3y + (L3 + L4)*sin(th2_3) + L6*sin(th4_3);
		ez = 60;												/**/ e3z = -60;
		
		ex_vec.push_back(ex);									/**/ e3x_vec.push_back(e3x);
		ey_vec.push_back(ey);									/**/ e3y_vec.push_back(e3y);
		ez_vec.push_back(ez);									/**/ e3z_vec.push_back(e3z);
		
	//----------------------------------------------------------------------------------------------------------
		e2x = a2x + (L3 + L4)*cos(th2_2) + L6*cos(th4_2); 			e4x = a4x + (L3 + L4)*cos(th2_4) + L6*cos(th4_4);
		e2y = a2y + (L3 + L4)*sin(th2_2) + L6*sin(th4_2);			e4y = a4y + (L3 + L4)*sin(th2_4) + L6*sin(th4_4);
		e2z = 60;													e4z = -60;
		
		e2x_vec.push_back(e2x);										e4x_vec.push_back(e4x);
		e2y_vec.push_back(e2y);										e4y_vec.push_back(e4y);
		e2z_vec.push_back(e2z);										e4z_vec.push_back(e4z);
		
	// Angulo phi3
		th3 = atan2((ey-dy),(ex-dx));								th3_3 = atan2((e3y-d3y),(e3x-d3x));
		th3_2 = atan2((e2y-d2y),(e2x-d2x));							th3_4 = atan2((e4y-d4y),(e4x-d4x));
				
		
	// Angulo para eslabon de efector final
		epsilon = acos((L4*L4 + L5*L5 - R2*R2)/(2*L4*L5));
		
		th5 = th4 - 30*pi/180;										th5_3 = th4_3 - 30*pi/180;
		th5_2 = th4_2 + 30*pi/180;									th5_4 = th4_4 + 30*pi/180;
		
		
	// Nodo G
		gx = -L7*cos(th5) + (L3 + L4)*cos(th2) + ax;					g3x = -L7*cos(th5_3) + (L3 + L4)*cos(th2_3) + a3x;
		gy = -L7*sin(th5) + (L3 + L4)*sin(th2) + ay;					g3y = -L7*sin(th5_3) + (L3 + L4)*sin(th2_3) + a3y;
		gz = 60;															g3z = -60;
		
		gx_vec.push_back(gx);											g3x_vec.push_back(g3x);
		gy_vec.push_back(gy);											g3y_vec.push_back(g3y);
		gz_vec.push_back(gz);											g3z_vec.push_back(g3z);
		
	//-----------------------------------------------------------------------------------------------------------------
		g2x = -L7*cos(th5_2) + (L3 + L4)*cos(th2_2) + a2x;				g4x = -L7*cos(th5_4) + (L3 + L4)*cos(th2_4) + a4x;
		g2y = -L7*sin(th5_2) + (L3 + L4)*sin(th2_2) + a2y;				g4y = -L7*sin(th5_4) + (L3 + L4)*sin(th2_4) + a4y;
		g2z = 60;														g4z = -60;
		
		g2x_vec.push_back(g2x);											g4x_vec.push_back(g4x);
		g2y_vec.push_back(g2y);											g4y_vec.push_back(g4y);
		g2z_vec.push_back(g2z);											g4z_vec.push_back(g4z);

//**************************************************************************************************************************		
//**************************************************************************************************************************
// Grafica los eslabones en gnuplot
		a[0] = 0;									/**/	aa[0] = 0;	 
		a[1] = 0;									/**/	aa[1] = 0;
		a[2] = 60;									/**/    aa[2] = -60; 
		c[0] = L1*cos(th0);							/**/    cc[0] = aa[0] + L1*cos(th0 - pi);
		c[1] = L1*sin(th0);							/**/    cc[1] = aa[1] + L1*sin(th0 - pi);
		c[2] = 60;									/**/	cc[2] = aa[2] + 0; 
		d[0] = c[0] + L3*cos(th2);					/**/	dd[0] = cc[0] + L3*cos(th2_3);
		d[1] = c[1] + L3*sin(th2);					/**/	dd[1] =	cc[1] + L3*sin(th2_3);
		d[2] = c[2];								/**/	dd[2] = cc[2];
		e[0] = d[0] + L4*cos(th2);					/**/	ee[0] = dd[0] + L4*cos(th2_3);
		e[1] = d[1] + L4*sin(th2);					/**/	ee[1] = dd[1] + L4*sin(th2_3);
		e[2] = 60;									/**/	ee[2] = -60;
		f[0] = e[0] + L6*cos(th4);					/**/	ff[0] = ee[0] + L6*cos(th4_3);
		f[1] = e[1] + L6*sin(th4);					/**/	ff[1] = ee[1] + L6*sin(th4_3);
		f[2] = 60;									/**/	ff[2] = -60;
		g[0] = e[0] - L7*cos(th5);					/**/	gg[0] = ee[0] - L7*cos(th5_3);
		g[1] = e[1] - L7*sin(th5);					/**/	gg[1] = ee[1] - L7*sin(th5_3);
		g[2] = 60;									/**/	gg[2] = -60;

		ifa[0] = 0;									/**/ 	ita[0] = 0;
		ifa[1] = 0;									/**/	ita[1] = 0;
		ifa[2] = 60;								/**/    ita[2] = -60;
		ifc[0] = L1*cos(th0 + pi);					/**/    itc[0] = L1*cos(th0);	
		ifc[1] = L1*sin(th0 + pi);					/**/    itc[1] = L1*sin(th0);	
		ifc[2] = 60;								/**/	itc[2] = -60;
		ifd[0] = ifc[0] + L3*cos(th2_2);            /**/	itd[0] = itc[0] + L3*cos(th2_4);
		ifd[1] = ifc[1] + L3*sin(th2_2);			/**/	itd[1] = itc[1] + L3*sin(th2_4);
		ifd[2] = 60;								/**/	itd[2] = -60;	
		ife[0] = ifd[0] + L4*cos(th2_2);			/**/	ite[0] = itd[0] + L4*cos(th2_4);
		ife[1] = ifd[1] + L4*sin(th2_2);			/**/	ite[1] = itd[1] + L4*sin(th2_4);
		ife[2] = 60;										ite[2] = -60;
		iff[0] = ife[0] + L6*cos(th4_2);					itf[0] = ite[0] + L6*cos(th4_4);
		iff[1] = ife[1] + L6*sin(th4_2);					itf[1] = ite[1] + L6*sin(th4_4);
		iff[2] = 60;										itf[2] = -60;
		ifg[0] = ife[0] - L7*cos(th5_2);					itg[0] = ite[0] - L7*cos(th5_4);
		ifg[1] = ife[1] - L7*sin(th5_2);					itg[1] = ite[1] - L7*sin(th5_4);
		ifg[2] = 60;										itg[2] = -60;



		// Siempre tiene que hacer un punto de retorno a->c , c->a

		points[0] = a; 								/**/  circle[0] = aa;
		points[1] = c; 								/**/  circle[1] = cc;
		points[2] = d;								/**/  circle[2] = dd;
		points[3] = e;								/**/  circle[3] = ee;
		points[4] = f;								/**/  circle[4] = ff;
		points[5] = e;								/**/  circle[5] = ee;
		points[6] = g;								/**/  circle[6] = gg;
		points[7] = e;								/**/  circle[7] = ee;
		points[8] = d;								/**/  circle[8] = dd;
		points[9] = c;								/**/  circle[9] = cc;
		points[10] = a;								/**/  circle[10] = aa;
		
		rojo[0] = ifa;									  rojo4[0] = ita;
		rojo[1] = ifc;									  rojo4[1] = itc;
		rojo[2] = ifd;									  rojo4[2] = itd;	
		rojo[3] = ife;									  rojo4[3] = ite;
		rojo[4] = iff;									  rojo4[4] = itf;
		rojo[5] = ife;									  rojo4[5] = ite;
		rojo[6] = ifg;									  rojo4[6] = itg;
		rojo[7] = ife;									  rojo4[7] = ite;
		rojo[8] = ifd;									  rojo4[8] = itd;
		rojo[9] = ifc;									  rojo4[9] = itc;
		rojo[10] = ifa;									  rojo4[10] = ita;
	//*******************************************************************************************************************
	//  Esta seccion fija y grafica en eslabon L2

		b2[0] = 30;									/**/	dtb[0] = 30;
		b2[1] = -15;								/**/    dtb[1] = -15;
		b2[2] = 60;							    	/**/	dtb[2] = -60;
		d2[0] = b2[0] + L2*cos(th1);				/**/	dtd[0] = dtb[0] + L2*cos(th1_3);
		d2[1] = b2[1] + L2*sin(th1); 				/**/	dtd[1] = dtb[1] + L2*sin(th1_3);
		d2[2] = 60;									/**/	dtd[2] = -60;
		
		ifb[0] = -30;								/**/	itb[0] = -30;
        ifb[1] = -15;								        itb[1] = -15;
        ifb[2] = 60;										itb[2] = -60;
	    ifd[0] = ifb[0] - L2*cos(th1_2);					itd[0] = itb[0] - L2*cos(th1_4);
	    ifd[1] = ifb[1] - L2*sin(th1_2);					itd[1] = itb[1] - L2*sin(th1_4);
		ifd[2] = 60;										itd[2] = -60;
	
		verde[0] = b2;								/**/	verde3[0] = dtb;
		verde[1] = d2;								/**/	verde3[1] = dtd;
		
		verde2[0] = ifb;									verde4[0] = itb;
		verde2[1] = ifd;									verde4[1] = itd;

	//********************************************************************************************************************
	// Esta seccion fija  y grafica en eslabon L5 

		f3[0] = 25;											dtf[0] = 25;
		f3[1] = 11.50;										dtf[1] = 11.50;
		f3[2] = 60;											dtf[2] = -60;
		g3[0] = f3[0] + L5*cos(th3);						dtg[0] = dtf[0] + L5*cos(th3_3);
		g3[1] = f3[1] + L5*sin(th3);						dtg[1] = dtf[1] + L5*sin(th3_3);				
		g3[2] = 60;											dtg[2] = -60;
	
		azul[0] = f3; 										azul3[0] = dtf;
		azul[1] = g3;										azul3[1] = dtg;

		ifj[0] = -25;										itj[0] = -25;
		ifj[1] = 11.50;										itj[1] = 11.50;
		ifj[2] = 60;										itj[2] = -60;
		ifk[0] = ifj[0] + L5*cos(th3_2);					itk[0] = itj[0] + L5*cos(th3_4);
		ifk[1] = ifj[1] + L5*sin(th3_2);					itk[1] = itj[1] + L5*sin(th3_4);
		ifk[2] = 60;										itk[2] = -60;

		
		azul2[0] = ifj;										azul4[0] = itj;
		azul2[1] = ifk;										azul4[1] = itk;

	//********************************************************************************************************************

		//gp << "set terminal pngcairo size 1000,900 \n";*
		//gp << "set output '" << num << ".png' \n";*
		if(gsm = true)
			//fb
		//gp << "set terminal gif color enhanced \n";
		//gp << "set output 'output.gif' \n";
		gp << "set grid \n";
		//gp << "set view equal xyz \n";
		//gp << "set view  60,120 \n";
		gp << "set encoding iso_8859_1 \n";
		//gp << "set key font 'Times New Roman,18' \n ";
		//gp << "set key spacing 1.25 \n";
		gp << "set key off \n";
		gp << "set ticslevel 0 \n"; // Para cambiar el nivel de eje Z 
		gp << "set xtics font 'Times New Roman,16' \n";
		gp << "set ytics font 'Times New Roman,16' \n";
		gp << "set ztics font 'Times New Roman,16' \n";
		gp << "set xlabel font 'Times New Roman,18' \n";
		gp << "set ylabel font 'Times New Roman,18' \n";
		gp << "set zlabel font 'Times New Roman,18' \n";
		gp << "set xlabel offset -3 \n";
		gp << "set ylabel offset -3 \n";
		gp << "set zlabel offset -3 \n";
		gp << "set xlabel 'X(cm)' \n";
		gp << "set ylabel 'Y(cm)' \n";
		gp << "set zlabel 'Z(cm)' \n";
		gp << "set xrange[-80:80] \n";
		gp << "set yrange[-80:80] \n";
		gp << "set zrange[-80:80] \n";
		gp << "set pointsize 2 \n";
		gp << "splot '-' u 3:1:2 w lp lt -1 lc -1 lw 5 t 'DF', '-' u 3:1:2 w lp lt -1 lc -1 lw 5 t 'DF2', '-' u 3:1:2 w lp lt -1 lc -1 lw 5 t 'DF3' , \
		             '-' u 3:1:2 w lp lt -1 lc 3  lw 5 t 'IF', '-' u 3:1:2 w lp lt -1 lc  3 lw 5 t 'IF2', '-' u 3:1:2 w lp lt -1 lc 3  lw 5 t 'IF3', \
		             '-' u 3:1:2 w lp lt -1 lc 9  lw 5 t 'DT', '-' u 3:1:2 w lp lt -1 lc  9 lw 5 t 'DT2', '-' u 3:1:2 w lp lt -1 lc 9  lw 5 t 'DT3',\
					 '-' u 3:1:2 w lp lt -1 lc 8  lw 5 t 'IT', '-' u 3:1:2 w lp lt -1 lc  8 lw 5 t 'IT2', '-' u 3:1:2 w lp lt -1 lc 8  lw 5 t 'IT3', \
					 '-' t 'Nodo A' w l lc 1 lw 3, 	 '-' t 'Nodo A2' w l lc 1 lw 3,  '-' t 'Nodo G' w l lc 1 lw 3, '-' t 'Nodo G' w l lc 1 lw 3  \n";
		gp.send1d(points);
		gp.send1d(verde);
		gp.send1d(azul);
		gp.send1d(rojo); // Pata izquierda frontal 
		gp.send1d(verde2); // Pata izquierda Frontal
		gp.send1d(azul2); // Pata izquierda Frontal
		//
		gp.send1d(circle);
		gp.send1d(verde3);
		gp.send1d(azul3);
		//
		gp.send1d(rojo4);
		gp.send1d(verde4);
		gp.send1d(azul4);
		gp.send1d(boost::make_tuple(g3z_vec,g3x_vec,g3y_vec)); // Grafica Trayectoria L1
		gp.send1d(boost::make_tuple(g2z_vec,g2x_vec,g2y_vec)); // Grafica Trayectoria L1
		gp.send1d(boost::make_tuple(gz_vec,gx_vec,gy_vec)); // Grafica Trayectoria L1
		gp.send1d(boost::make_tuple(g4z_vec,g4x_vec,g4y_vec)); // Grafica Trayectoria L1
		iter+=step;						
	}
	
	return 0;
}


