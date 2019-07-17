# FreeCAD Animation
# August 5th 2015

# execfile("/home/gerson/Thesis/Plataforma/animar4.py")

import os
os.chdir("/home/gerson/Thesis/Plataforma")

import Part
from PyQt4 import QtCore, QtGui
from FreeCAD import Base
from math import cos, sin, degrees, radians
import sys

sys.path.append('/home/gerson/Thesis/Plataforma')
import acoplar4

# Contador que delimita el numero de punto graficados por la trayectoria
counter = 0

# Carga modulo Python - C++
animation=reload(acoplar4)
a=animation.acoplar4()
a.inicializar()

# Crear Archivo donde se guarda la trayectoria
'''
puntos = open("/home/gerson/Thesis/Plataforma/trayecto.asc","w")
puntos.close()
trayectoria = App.ActiveDocument.addObject("Points::ImportAscii","trayecto")
trayectoria.FileName = "/home/gerson/Thesis/Plataforma/trayecto.asc"
'''

def circulo( ):
	global a, counter
	a.calcular()
	a.calcular2()
	a.calcular3()
	a.calcular4()
	a.calcular5()
	
	z = 0
	pi =  3.141592653589793

	# Angulos Principlaes
	phi0=degrees(a.phi0)
	phi1=degrees(a.phi1)
	phi2=degrees(a.phi2)
	phi3=degrees(a.phi3)
	phi4=degrees(a.phi4)
	phi5=degrees(a.phi5)
	# Posicion de nodos
	ax=a.ax   
	ay=a.ay 
	cx=a.cx
	cy=a.cy
	fx=a.fx
	fy=a.fy
	fx2=a.fx2
	fy2=a.fy2
	ex=a.ex
	ey=a.ey
	gx=a.gx
	gy=a.gy
	# Posiciones Fijas
	bx=a.bx
	by=a.by
	dx=a.dx
	dy=a.dy
	##################################################################
	# Angulos principales extremidad izquierda
	th0=degrees(a.th0)
	th1=degrees(a.th1)
	th2=degrees(a.th2)
	th3=degrees(a.th3)
	th4=degrees(a.th4)
	th5=degrees(a.th5)
	# Posiciones Fijas Izquierda
	b2x=a.b2x
	b2y=a.b2y
	d2x=a.d2x
	d2y=a.d2y
	# Nodos extremidad izquierda
	a2x=a.a2x   
	a2y=a.a2y 
	c2x=a.c2x
	c2y=a.c2y
	e2x=a.e2x
	e2y=a.e2y
	f3x=a.f3x
	f3y=a.f3y
	f4x=a.f4x
	f4y=a.f4y
	g2x=a.g2x
	g2y=a.g2y
	##################################################################
	# Angulos principales extremidad derecha trasera
	sig0=degrees(a.sig0)
	sig1=degrees(a.sig1)
	sig2=degrees(a.sig2)
	sig3=degrees(a.sig3)
	sig4=degrees(a.sig4)
	sig5=degrees(a.sig5)
	# Posiciones Fijas Derecha Trasera
	b3x=a.b3x
	b3y=a.b3y
	d3x=a.d3x
	d3y=a.d3y
	# Nodos extremidad Derecha Trasera
	a3x=a.a3x   
	a3y=a.a3y 
	c3x=a.c3x
	c3y=a.c3y
	f5x=a.f5x
	f5y=a.f5y
	f6x=a.f6x
	f6y=a.f6y
	e3x=a.e3x
	e3y=a.e3y
	##################################################################
	# Angulos principales extremidad izquierda trasera
	rh0=degrees(a.rh0)
	rh1=degrees(a.rh1)
	rh2=degrees(a.rh2)
	rh3=degrees(a.rh3)
	rh4=degrees(a.rh4)
	rh5=degrees(a.rh5)
	# Posiciones Fijas Derecha Trasera
	b4x=a.b4x
	b4y=a.b4y
	d4x=a.d4x
	d4y=a.d4y
	# Nodos extremidad Derecha Trasera
	a4x=a.a4x   
	a4y=a.a4y 
	c4x=a.c4x
	c4y=a.c4y
	f7x=a.f7x
	f7y=a.f7y
	f8x=a.f8x
	f8y=a.f8y
	e4x=a.e4x
	e4y=a.e4y
	##################################################################
	# Movimiento de engranes
	omega0=degrees(a.omega0)
	#print (rh1)
	# Movimiento de eslabones en FreeCAD
	# Extremidad Derecha Frontal
	# Eslabon L1
	App.getDocument("robo3").Part__Feature004.Placement=App.Placement(App.Vector(58,0,0), App.Rotation(phi0,0,0), App.Vector(0,0,0))
	# Eslabon L2
	App.getDocument("robo3").Part__Feature083.Placement=App.Placement(App.Vector(bx,by,15), App.Rotation(phi1,0,0), App.Vector(0,0,0)) 
	# Eslabon L3
	App.getDocument("robo3").Part__Feature085.Placement=App.Placement(App.Vector(ax,ay,5), App.Rotation(phi2,0,0), App.Vector(0,0,0)) 
	# Eslabon L4
	App.getDocument("robo3").Part__Feature056.Placement=App.Placement(App.Vector(fx,fy,10), App.Rotation(phi2,0,0), App.Vector(0,0,0)) 
	# Eslabon L5
	App.getDocument("robo3").Part__Feature084.Placement=App.Placement(App.Vector(dx,dy,10), App.Rotation(phi3,0,0), App.Vector(0,0,0))
	# Eslabon L6
	App.getDocument("robo3").Part__Feature008.Placement=App.Placement(App.Vector(fx2,fy2,30), App.Rotation(phi4,0,180), App.Vector(0,0,0))
	# Eslabon L7
	App.getDocument("robo3").Part__Feature086.Placement=App.Placement(App.Vector(fx2,fy2,20), App.Rotation(phi5+180,0,180), App.Vector(0,0,0))
	# Part Features originales : 003,005,006,007,008,009
	##################################################################
	# Extremidad Izquierda Frontal
	# Eslabon L1
	#App.getDocument("robo3").Part__Feature010.Placement=App.Placement(App.Vector(-127,0,0), App.Rotation(th0+180,0,0), App.Vector(0,0,0))
	# Eslabon L2
	App.getDocument("robo3").Part__Feature087.Placement=App.Placement(App.Vector(b2x,b2y,15), App.Rotation(th1+180,0,0), App.Vector(0,0,0))
	# Eslabon L3
	App.getDocument("robo3").Part__Feature088.Placement=App.Placement(App.Vector(a2x,a2y,5), App.Rotation(th2,0,0), App.Vector(0,0,0)) 
	# Eslabon L4
	#App.getDocument("robo3").Part__Feature061.Placement=App.Placement(App.Vector(f3x,f3y,10), App.Rotation(th2,0,0), App.Vector(0,0,0)) 
	# Eslabon L5
	App.getDocument("robo3").Part__Feature089.Placement=App.Placement(App.Vector(d2x,d2y,10), App.Rotation(th3,0,0), App.Vector(0,0,0))
	# Eslabon L6
	#App.getDocument("robo3").Part__Feature063.Placement=App.Placement(App.Vector(f4x,f4y,0), App.Rotation(th4,0,0), App.Vector(0,0,0))
	# Eslabon L7
	App.getDocument("robo3").Part__Feature090.Placement=App.Placement(App.Vector(f4x,f4y,15), App.Rotation(th5+180,0,0), App.Vector(0,0,0))
	# Part Feature original : 012,013,014,015,016,017
	##################################################################
	# Movimiento de engranes
	# Engrane motor
	App.getDocument("robo3").Part__Feature.Placement=App.Placement(App.Vector(0,0,0), App.Rotation(-omega0,0,0), App.Vector(0,0,0)) 
	# Engrane conducido
	App.getDocument("robo3").Part__Feature019.Placement=App.Placement(App.Vector(58,0,0), App.Rotation(omega0*(13.0/26.0)-7.0,0,0), App.Vector(0,0,0))
	# Engrane conducido 2
	App.getDocument("robo3").Part__Feature020.Placement=App.Placement(App.Vector(-58,0,0), App.Rotation(omega0*(13.0/26.0),0,0), App.Vector(0,0,0))  
	##################################################################
	# Extremidad Trasera Derecha
	# Eslabon L1
	#App.getDocument("robo2").Part__Feature033.Placement=App.Placement(App.Vector(127,0,-440), App.Rotation(sig0-pi,0,0), App.Vector(0,0,0))
	# Eslabon L2
	App.getDocument("robo3").Part__Feature092.Placement=App.Placement(App.Vector(b3x,b3y,-220), App.Rotation(sig1,0,0), App.Vector(0,0,0))
	# Eslabon L3
	App.getDocument("robo3").Part__Feature093.Placement=App.Placement(App.Vector(a3x,a3y,-220), App.Rotation(sig2,0,0), App.Vector(0,0,0))  
	# Eslabon L4
	#App.getDocument("robo3").Part__Feature067.Placement=App.Placement(App.Vector(f5x,f5y,-220), App.Rotation(sig2,0,0), App.Vector(0,0,0)) 
	# Eslabon L5
	App.getDocument("robo3").Part__Feature094.Placement=App.Placement(App.Vector(d3x,d3y,-225), App.Rotation(sig3,0,0), App.Vector(0,0,0))
	# Eslabon L6
	#App.getDocument("robo3").Part__Feature069.Placement=App.Placement(App.Vector(f6x,f6y,-200), App.Rotation(sig4,0,180), App.Vector(0,0,0))
	# Eslabon L7
	App.getDocument("robo3").Part__Feature095.Placement=App.Placement(App.Vector(f6x,f6y,-215), App.Rotation(sig5+180,0,180), App.Vector(0,0,0))
	# Part Feature : 030,029,031,032,033,034
	##################################################################
	# Extremidad Trasera Izquierda
	# Eslabon L1
	#App.getDocument("robo3").Part__Feature033.Placement=App.Placement(App.Vector(-127,0,-440), App.Rotation(rh0,0,0), App.Vector(0,0,0)) 
	# Eslabon L2
	App.getDocument("robo3").Part__Feature096.Placement=App.Placement(App.Vector(b4x,b4y,-220), App.Rotation(rh1+180,0,0), App.Vector(0,0,0))
	# Eslabon L3
	App.getDocument("robo3").Part__Feature097.Placement=App.Placement(App.Vector(a4x,a4y,-220), App.Rotation(rh2,0,0), App.Vector(0,0,0))
	# Eslabon L4
	#App.getDocument("robo3").Part__Feature073.Placement=App.Placement(App.Vector(f7x,f7y,-220), App.Rotation(rh2,0,0), App.Vector(0,0,0)) 
	# Eslabon L5
	App.getDocument("robo3").Part__Feature098.Placement=App.Placement(App.Vector(d4x,d4y,-225), App.Rotation(rh3,0,0), App.Vector(0,0,0))
	# Eslabon L6
	#App.getDocument("robo3").Part__Feature075.Placement=App.Placement(App.Vector(f8x,f8y,-210), App.Rotation(rh4,0,0), App.Vector(0,0,0))
	# Eslabon L7
	App.getDocument("robo3").Part__Feature099.Placement=App.Placement(App.Vector(f8x,f8y,-220), App.Rotation(rh5+180,0,0), App.Vector(0,0,0))
	# Part Feature : 035,036,037,038,039,040
	##################################################################
	# Trayectoria de eslabones utilizando nube de puntos
'''	
	if(counter%1 == 0 and counter <=3600):
		puntos = open("/home/gerson/Thesis/Plataforma/trayecto.asc","a")
		print >> puntos, gx, gy, z
		puntos.close() 
		if( counter%36 == 0 ):
			App.getDocument("robo3").removeObject("trayecto")
			trayectoria = App.ActiveDocument.addObject("Points::ImportAscii","trayecto")
			trayectoria.FileName = "/home/gerson/Thesis/Plataforma/trayecto.asc"
			FreeCADGui.getDocument("robo3").getObject("trayecto").PointSize = 3.00
			FreeCADGui.getDocument("robo3").getObject("trayecto").ShapeColor = (0.00,0.00,1.00) #
			App.ActiveDocument.recompute()
	counter=counter+1
'''			

# Timer utilizado para evitar que el programa se congele
timer=QtCore.QTimer()
timer.timeout.connect(circulo) 
timer.start(10)
