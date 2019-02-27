minrt: main.o Point.o Vec.o Plane.o Sphere.o Color.o
	g++ main.o Point.o Vec.o Plane.o Sphere.o Color.o -o minrt
main.o: main.cpp
	g++ -c main.cpp
Point.o: Point.cpp
	g++ -c Point.cpp
Vec.o: Vec.cpp
	g++ -c Vec.cpp
Plane.o: Plane.cpp
	g++ -c Plane.cpp
Sphere.o: Sphere.cpp
	g++ -c Sphere.cpp
Color.o: Color.cpp
	g++ -c Color.cpp
clean:
	rm *.o minrt