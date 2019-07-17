/*
 Klann Mechanism animation C++ Class
 
 Author: Gerson Santos
 Date: August 5th 2015
*/

#include <boost/python.hpp>
#include <iostream>
#include <armadillo>
#include <fstream>
#include <cmath>

#define pi 3.141592653589793
using namespace arma;
using namespace std;

class animation{
	private:
		// Longitudes de los eslabones
		double l1, l2,l3,l4,l5,l6,l7;
	public:
		//********************************************************************** Extremidad Derecha Delantera
		// Angulos de eslabones
 		double phi0,phi1,phi2,phi3,phi4,phi5;
 		// Angulos por trigonometria
 		double alfa,beta,gamma,delta;
 		// Posicion de eslabones
 		double ax,ay,cx,cy,ex,ey,fx,fy,fx2,fy2,gx,gy;
 		// Posicion fija
 		double bx,by,dx,dy;
 		// Variables Virtuales
 		double r1,r2,r3,r4,r5,r6,r7,r8;
 		//*********************************************************************** Extremidad Izquierda Delantera
 		// Angulos de eslabones
 		double th0,th1,th2,th3,th4,th5;
 		// Posicion de eslabones
 		double a2x,a2y,c2x,c2y,e2x,e2y,g2x,g2y,f3x,f3y,f4x,f4y;
 		// Posicion Fija
 		double b2x,b2y,d2x,d2y;
 		// Angulos por trigonometria
 		double alfa2,beta2,gamma2,delta2;
 		//********************************************************************** Extremidad Derecha Trasera
 		// Angulos de eslabones
 		double sig0,sig1,sig2,sig3,sig4,sig5;
 		// Posicion de eslabones
 		double a3x,a3y,c3x,c3y,f5x,f5y,f6x,f6y,e3x,e3y,g3x,g3y;
 		// Posicion Fija
 		double b3x, b3y, d3x, d3y;
 		// Angulos por Trigonometria
 		double alfa3, beta3,gamma3,delta3;
 		 //********************************************************************** Extremidad Izquierda Trasera
 		// Angulos de eslabones
 		double rh0,rh1,rh2,rh3,rh4,rh5;
 		// Posicion de eslabones
 		double a4x,a4y,c4x,c4y,f7x,f7y,f8x,f8y,e4x,e4y,g4x,g4y;
 		// Posicion Fija
 		double b4x,b4y,d4x,d4y;
 		// Angulos por Trigonometria
 		double alfa4, beta4,gamma4,delta4;
 		//********************************************************************** Engranes - Mecanismo
 		double gear1,gear2;
 		double omega0, omega1, z0, z1, z2, z3;
 		// Funcion para inicializar variables
 		void inicializar( )		
		{
			// Angulos 
			phi0 = 0;		/**/ th0 = 0;		/**/ omega0 = 0;		
			phi1 = 0;		/**/ th1 = 0;		/**/ omega1 = 0;
			phi2 = 0;       /**/ th2 = 0;		/**/ 
			phi3 = 0;       /**/ th3 = 0;       /**/ 
			phi4 = 0;       /**/ th4 = 0;       /**/ 
			phi5 = 0;       /**/ th5 = 0;
			
			sig0 = 0;		/**/ rh0 = 0;
			sig1 = 0;		/**/ rh1 = 0;
			sig2 = 0;		/**/ rh2 = 0;
			sig3 = 0;		/**/ rh3 = 0;
			sig4 = 0;		/**/ rh4 = 0;
			sig5 = 0;		/**/ rh5 = 0;
			// Posicion de nodos
			// DerF              IzqF
			ax = 0;			/**/ a2x = 0;
			ay = 0;			/**/ a2y = 0;
			cx = 0;     	/**/ c2x = 0;
			cy = 0;     	/**/ c2y = 0;
			ex = 0;     	/**/ e2x = 0;
			ey = 0;     	/**/ e2y = 0;
			gx = 0;     	/**/ g2x = 0;
			gy = 0;     	/**/ g2y = 0;
			
			// DerT				IzqT
			a3x = 0;		/**/ a4x = 0;
			a3y = 0;		/**/ a4y = 0;
			c3x = 0;		/**/ c4x = 0;
			c3y = 0;		/**/ c4y = 0;
			e3x = 0;		/**/ e4x = 0;
			e3y = 0;		/**/ e4y = 0;
			g3x = 0;		/**/ g4x = 0; 
			g3y = 0;		/**/ g4y = 0;
			
			// Puntos fijos
			bx = 75+58; 		        /**/   b2x = -75-58;
			by = -37.5;		            /**/   b2y = -37.5;
			dx = 62.5+58;	     	    /**/   d2x = -62-58;
			dy = 28.75;		            /**/   d2y = 28.75;
			
			b3x = 75+58;				/**/	b4x = -75-58;
			b3y = -37.5;				/**/	b4y = -37.5;
			d3x = 62+58;				/**/	d4x = -62-58;
			d3y = 28.75;				/**/	d4y = 28.75;
			
			// Longitud de eslabones
			l1 = 32.5;		
			l2 = 50;		
			l3 = 75;		
			l4 = 70;		
			l5 = 62.5;		
			l6 = 62.5;		
			l7 = 75;		
		}
		// Funcion principal
		void calcular()
		{
			z0 = (13.0/26.0);
						
			phi0 +=(.5* pi/180)*z0 ;
					
			// Eslabon l1
			ax = l1*cos(phi0) + 58;
			ay = l1*sin(phi0);
			// Variable Virtual R1
			r1 = sqrt(pow(ax-bx,2) + pow(ay-by,2));
			// Calculo de angulo alfa
			alfa = atan2((ay - by),(ax - bx));
			// Calculo de angulo beta
			// utilizando ley de cosenos
			beta = acos((r1*r1+l2*l2 - l3*l3)/(2*r1*l2));
			// Angulo de restriccion phi1
			phi1 = alfa - beta;
			// Nodo C
			cx = bx + l2*cos(phi1);
			cy = by + l2*sin(phi1);
			// Calculo de angulo phi2
			phi2 = atan2((cy-ay),(cx-ax));
			// Nodo F
			fx =  l3*cos(phi2) + ax;
			fy =  l3*sin(phi2) + ay; 
			// Nodo F2
			fx2 =  l4*cos(phi2) + l3*cos(phi2) + l1*cos(phi0)+58; // Se le suma la distancia para transladar la nube de puntos
			fy2 =  l4*sin(phi2) + l3*sin(phi2) + l1*sin(phi0); 
		
			//********************* Termina Hoekens ******************************************** OK
			//********************* Empieza Klann ********************************************** OK

			// Variable Virtual r2, angulo de restriccion
			r2 = sqrt(pow(fx2-dx,2) + pow(fy2-dy,2));
			// Angulo gamma	
			gamma = atan2((fy2-dy),(fx2-dx)); // Se agrega pi
			// Angulo delta
			delta = acos((r2*r2 + l6*l6 -l5*l5)/(2*r2*l6));
			// Angulo phi4
			phi4 = gamma - delta - pi; // Se le cambia el signo
			// Nodo e			
			ex = ax + (l3 + l4)*cos(phi2) + l6*cos(phi4); 
			ey = ay + (l3 + l4)*sin(phi2) + l6*sin(phi4); 
			// Angulo de restriccion phi3 para eslabon rc
			phi3 = atan2((ey-dy),(ex-dx));
			// Angulo efector final
			phi5 = phi4 - 30*pi/180;
			// Nodo G 
			gx = -l7*cos(phi5) + (l3 + l4)*cos(phi2) + ax;
			gy = -l7*sin(phi5) + (l3 + l4)*sin(phi2) + ay; 
							
		}
		void calcular2()
		{
			z1 = (13.0/26.0);
		
		 	th0 +=(.5* pi/180)*z1;
			// Eslabon l1
			a2x = l1*cos(th0 - pi) -58;
			a2y = l1*sin(th0 - pi);
			// Variable Virtual R3
			r3 = sqrt(pow(a2x - b2x,2) + pow(a2y - b2y,2));	
			// Angulo Alfa
			alfa2 = atan2((a2y - b2y),(a2x - b2x));	
			// Angulo Beta
			beta2 = acos((r3*r3+l2*l2 -l3*l3)/(2*r3*l2));   	
			// Angulo th1
			th1 = alfa2 + beta2 + pi;
			// Nodo C2
			c2x = b2x - l2*cos(th1);	
			c2y = b2y - l2*sin(th1);	
			// Angulo th2
			th2 = atan2((c2y-a2y),(c2x-a2x));
			// Nodo F3
			f3x =  l3*cos(th2) + a2x;
			f3y =  l3*sin(th2) + a2y; 
			// Nodo F4
			f4x =  l4*cos(th2) + l3*cos(th2) + l1*cos(th0 + pi)-58;
			f4y =  l4*sin(th2) + l3*sin(th2) + l1*sin(th0 + pi); 
			//********************* Termina Hoekens ******************************************** OK
			//********************* Empieza Klann ********************************************** OK
			// Variable Virtual r4, angulo de restriccion
			r4 = sqrt(pow(f4x-d2x,2) + pow(f4y-d2y,2));
			// Angulo gamma2	
			gamma2 = atan2((f4y-d2y),(f4x-d2x));
			// Angulo delta2
			delta2 = acos((r4*r4 + l6*l6 -l5*l5)/(2*r4*l6));
			// Angulo th4
			th4 = gamma2 + delta2 + pi;
			// Nodo E
			e2x = a2x + (l3 + l4)*cos(th2) + l6*cos(th4);
			e2y = a2y + (l3 + l4)*sin(th2) + l6*sin(th4);
			// Angulo th3
			th3 = atan2((e2y-d2y),(e2x-d2x));
			// Angulo th5
			th5 =  th4 + 30*pi/180;
			// Nodo G
			g2x = -l7*cos(th5) + (l3 + l4)*cos(th2) + a2x;
			g2y = -l7*sin(th5) + (l3 + l4)*sin(th2) + a2y;
			
		}
		
		void calcular3()
		{
			// Variables para movimiento de engranes
			omega0 +=.5* pi/180; 
			omega1 -=.5* pi/180;
		
		}
		
		void calcular4()
		{
			z2 = (13.0/26.0);
						
			sig0 +=(.5* pi/180)*z2 ;
			// Eslabon l1
			a3x = l1*cos(sig0 - pi) + 58;
			a3y = l1*sin(sig0 - pi);
			// Variable Virtual R5
			r5 = sqrt(pow(a3x-b3x,2) + pow(a3y-b3y,2));
			// Calculo de angulo alfa
			alfa3 = atan2((a3y - b3y),(a3x - b3x));
			// Calculo de angulo beta
			// utilizando ley de cosenos
			beta3 = acos((r5*r5+l2*l2 - l3*l3)/(2*r5*l2));
			// Angulo de restriccion phi1
			sig1 = alfa3 - beta3;
			// Nodo C
			c3x = b3x + l2*cos(sig1);
			c3y = b3y + l2*sin(sig1);
			// Angulo th2
			sig2 = atan2((c3y-a3y),(c3x-a3x));
			// Nodo F5
			f5x = l3*cos(sig2) + a3x;
			f5y = l3*sin(sig2) + a3y;
	
			f6x =  l4*cos(sig2) + l3*cos(sig2) + l1*cos(sig0-pi)+58;
			f6y =  l4*sin(sig2) + l3*sin(sig2) + l1*sin(sig0-pi); 
			//********************* Termina Hoekens ******************************************** OK
			//********************* Empieza Klann ********************************************** OK
		
			// Variable Virtual r6, angulo de restriccion
			r6 = sqrt(pow(f6x-d3x,2) + pow(f6y-d3y,2));
			// Angulo gamma3
			gamma3 = atan2((f6y-d3y),(f6x-d3x));
			// Angulo delta3
			delta3 = acos((r6*r6 + l6*l6 - l5*l5)/(2*r6*l6));
			// Angulo sigma4
			sig4 = gamma3 - delta3 - pi; 
			// Nodo E
			e3x = a3x + (l3 + l4)*cos(sig2) + l6*cos(sig4);
			e3y = a3y + (l3 + l4)*sin(sig2) + l6*sin(sig4);
			// Angulo sigma3			
			sig3 = atan2((e3y-d3y),(e3x-d3x));
			// Angulo sigma5	
			sig5 = sig4 - 30*pi/180;;
			// Nodo G
			g3x = -l7*cos(sig5) + (l3 + l4)*cos(sig2) + a3x;
			g3y = -l7*sin(sig5) + (l3 + l4)*sin(sig2) + a3y;		
		}
		
		void calcular5()
		{
			z3 = (13.0/26.0);
						
			rh0 +=(.5* pi/180)*z3;
			// Eslabon L1
			a4x = l1*cos(rh0)-58;
			a4y = l1*sin(rh0);
			
			r7 = sqrt(pow(a4x-b4x,2) + pow(a4y-b4y,2));	
			
			alfa4 = atan2((a4y - b4y),(a4x - b4x));	
			
			beta4 = acos((r7*r7+l2*l2 -l3*l3)/(2*r7*l2));
			
			rh1 = alfa4 + beta4 + pi;
			
			c4x = b4x - l2*cos(rh1);
			c4y = b4y - l2*sin(rh1);	
			
			rh2 = atan2((c4y-a4y),(c4x-a4x));
			
			f7x = l3*cos(rh2) + a4x;	
			f7y = l3*sin(rh2) + a4y;
			
			f8x = l4*cos(rh2) + l3*cos(rh2) + l1*cos(rh0)-58;
			f8y = l4*sin(rh2) + l3*sin(rh2) + l1*sin(rh0);
			
			r8 = sqrt(pow(f8x-d4x,2) + pow(f8y-d4y,2));
			
			gamma4 = atan2((f8y-d4y),(f8x-d4x));
			
			delta4 = acos((r8*r8 + l6*l6 - l5*l5)/(2*r8*l6));
			
			rh4 = gamma4 + delta4 + pi;
			
			e4x = a4x + (l3 + l4)*cos(rh2) + l6*cos(rh4);
			e4y = a4y + (l3 + l4)*sin(rh2) + l6*sin(rh4);
			
			rh3 = atan2((e4y-d4y),(e4x-d4x));
			
			rh5 = rh4 + 30*pi/180;
						
			g4x = -l7*cos(rh5) + (l3 + l4)*cos(rh2) + a4x;
			g4y = -l7*sin(rh5) + (l3 + l4)*sin(rh2) + a4y;
		
		}

};


// Modulo Python para usar variables en anima.py
BOOST_PYTHON_MODULE(acoplar4)
{
	using namespace boost::python;
	class_<animation>("acoplar4")
		.def("inicializar", &animation::inicializar)		
		.def("calcular", &animation::calcular)
		.def_readwrite("ax", &animation::ax)
		.def_readwrite("ay", &animation::ay)
		.def_readwrite("cx", &animation::cx)
		.def_readwrite("cy", &animation::cy)
		.def_readwrite("fx", &animation::fx)
		.def_readwrite("fy", &animation::fy)
		.def_readwrite("fx2", &animation::fx2)
		.def_readwrite("fy2", &animation::fy2)
		.def_readwrite("ex", &animation::ex)
		.def_readwrite("ey", &animation::ey)
		.def_readwrite("gx", &animation::gx)
		.def_readwrite("gy", &animation::gy)
		.def_readwrite("bx", &animation::bx)
		.def_readwrite("by", &animation::by)
		.def_readwrite("dx", &animation::dx)
		.def_readwrite("dy", &animation::dy)
		.def_readwrite("phi0", &animation::phi0)
		.def_readwrite("phi1", &animation::phi1)
		.def_readwrite("phi2", &animation::phi2)
		.def_readwrite("phi3", &animation::phi3)
		.def_readwrite("phi4", &animation::phi4)
		.def_readwrite("phi5", &animation::phi5)
		.def("calcular2", &animation::calcular2)	 // Extremidad Izquierda
		.def_readwrite("a2x", &animation::a2x)
		.def_readwrite("a2y", &animation::a2y)
		.def_readwrite("c2x", &animation::c2x)
		.def_readwrite("c2y", &animation::c2y)
		.def_readwrite("e2x", &animation::e2x)
		.def_readwrite("e2y", &animation::e2y)
		.def_readwrite("g2x", &animation::g2x)
		.def_readwrite("g2y", &animation::g2y)
		.def_readwrite("f3x", &animation::f3x)
		.def_readwrite("f3y", &animation::f3y)
		.def_readwrite("f4x", &animation::f4x) 
		.def_readwrite("f4y", &animation::f4y)
		.def_readwrite("th0", &animation::th0)
		.def_readwrite("th1", &animation::th1)
		.def_readwrite("th2", &animation::th2)
		.def_readwrite("th3", &animation::th3)
		.def_readwrite("th4", &animation::th4)
		.def_readwrite("th5", &animation::th5)
		.def_readwrite("b2x", &animation::b2x)
		.def_readwrite("b2y", &animation::b2y)
		.def_readwrite("d2x", &animation::d2x)
		.def_readwrite("d2y", &animation::d2y)
		.def("calcular3", &animation::calcular3)		// Movimiento de Engranes
		.def_readwrite("omega0", &animation::omega0)
		.def_readwrite("omega1", &animation::omega1)
		.def("calcular4", &animation::calcular4)
		.def_readwrite("a3x", &animation::a3x)
		.def_readwrite("a3y", &animation::a3y)
		.def_readwrite("c3x", &animation::c3x)
		.def_readwrite("c3y", &animation::c3y) 
		.def_readwrite("b3x", &animation::b3x)
		.def_readwrite("b3y", &animation::b3y)
		.def_readwrite("d3x", &animation::d3x)
		.def_readwrite("d3y", &animation::d3y)
		.def_readwrite("f5x", &animation::f5x)
		.def_readwrite("f5y", &animation::f5y)
		.def_readwrite("f6x", &animation::f6x)
		.def_readwrite("f6y", &animation::f6y)
		.def_readwrite("e3x", &animation::e3x)
		.def_readwrite("e3y", &animation::e3y)
		.def_readwrite("g3x", &animation::g3x)
		.def_readwrite("g3y", &animation::g3y)
		.def_readwrite("sig0", &animation::sig0)
		.def_readwrite("sig1", &animation::sig1)
		.def_readwrite("sig2", &animation::sig2)
		.def_readwrite("sig3", &animation::sig3)
		.def_readwrite("sig4", &animation::sig4)
		.def_readwrite("sig5", &animation::sig5)
		.def("calcular5", &animation::calcular5)
		.def_readwrite("a4x", &animation::a4x)
		.def_readwrite("a4y", &animation::a4y)
		.def_readwrite("c4x", &animation::c4x)
		.def_readwrite("c4y", &animation::c4y) 
		.def_readwrite("b4x", &animation::b4x)
		.def_readwrite("b4y", &animation::b4y)
		.def_readwrite("d4x", &animation::d4x)
		.def_readwrite("d4y", &animation::d4y)
		.def_readwrite("f7x", &animation::f7x)
		.def_readwrite("f7y", &animation::f7y)
		.def_readwrite("f8x", &animation::f8x)
		.def_readwrite("f8y", &animation::f8y)
		.def_readwrite("e4x", &animation::e4x)
		.def_readwrite("e4y", &animation::e4y)
		.def_readwrite("g4x", &animation::g4x)
		.def_readwrite("g4y", &animation::g4y)
		.def_readwrite("rh0", &animation::rh0)
		.def_readwrite("rh1", &animation::rh1)
		.def_readwrite("rh2", &animation::rh2)
		.def_readwrite("rh3", &animation::rh3)
		.def_readwrite("rh4", &animation::rh4)
		.def_readwrite("rh5", &animation::rh5);
}

// Para compilar
/*
 
g++ -g -shared -fPIC acoplar4.cpp -o acoplar4.so -I/usr/include/python2.7 -lpython2.7 -lboost_python-2.7 -larmadillo -llapack -lboost_iostreams -lboost_system -lboost_filesystem

*/
