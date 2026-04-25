GCC = g++
CXXFLAGS = -std=c++11

# Build the final submission executable from all production sources.
PA4: main.o GameCommand.o Model.o View.o Mage.o RoamingDemon.o DemonHideout.o ManaSpire.o Building.o GameObject.o Point2D.o Vector2D.o
	$(GCC) $(CXXFLAGS) main.o GameCommand.o Model.o View.o Mage.o RoamingDemon.o DemonHideout.o ManaSpire.o Building.o GameObject.o Point2D.o Vector2D.o -o PA4

main.o: main.cpp
	$(GCC) $(CXXFLAGS) -c main.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) $(CXXFLAGS) -c GameCommand.cpp

Model.o: Model.cpp
	$(GCC) $(CXXFLAGS) -c Model.cpp

View.o: View.cpp
	$(GCC) $(CXXFLAGS) -c View.cpp

Mage.o: Mage.cpp
	$(GCC) $(CXXFLAGS) -c Mage.cpp

RoamingDemon.o: RoamingDemon.cpp
	$(GCC) $(CXXFLAGS) -c RoamingDemon.cpp

DemonHideout.o: DemonHideout.cpp
	$(GCC) $(CXXFLAGS) -c DemonHideout.cpp

ManaSpire.o: ManaSpire.cpp
	$(GCC) $(CXXFLAGS) -c ManaSpire.cpp

Building.o: Building.cpp
	$(GCC) $(CXXFLAGS) -c Building.cpp

GameObject.o: GameObject.cpp
	$(GCC) $(CXXFLAGS) -c GameObject.cpp

Point2D.o: Point2D.cpp
	$(GCC) $(CXXFLAGS) -c Point2D.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) $(CXXFLAGS) -c Vector2D.cpp

clean:
	rm -f *.o PA4
