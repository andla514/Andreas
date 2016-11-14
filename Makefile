# Filkataloger där andra delar av programet finns.
SFML = ../SFML

# Diagnosmeddelanden från kompilatorn (g++) filtreras av gccfilter.
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++14 -Wpedantic -Wall -Wextra -Werror 
#-Weffc++

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
SFML_installpath = -DSFML_STATIC -I SFML/include 
SFML_lib = -L SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
EXTRA_TAGS= -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system

# Objektkodsmoduler som ingår i den kompletta boombox.
<<<<<<< HEAD
OBJECTS = Item.o Bomb.o Matrix_Map.o Game.o Main_game.o Explosion.o
=======
OBJECTS = Character.o Item.o Bomb.o Matrix_Map.o Game.o Main_game.o Explosion.o Timer.o
>>>>>>> refs/remotes/origin/master

# Huvudmål - skapas med kommandot 'make' eller 'make boombox'.
boombox: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) Character.cc -o boombox $(OBJECTS) -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
	#$(OBJECTS) Makefile
	#$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) $(EXTRA_TAGS) -o boombox $(OBJECTS)

explosion_test: Explosion.o test_main.o Explosion_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) Explosion.o test_main.o Explosion_test.cc -o explosion_test
	
bomb_test: Bomb.o test_main.o Bomb_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Bomb.o Bomb_test.cc -o bomb_test

game_test: Game.o Matrix_Map.o Item.o test_main.o Game_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Game.o matrix_map.o Item.o Game_test.cc -o game_test
	
character_test: Character.o test_main.o Character_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Character.o Character_test.cc -o character_test

character_test2:Bomb.o Item.o Game.o Matrix_Map.o Main_game.o Explosion.o 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) Character.cc Character_test.cc -o -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
	
item_test: Item.o test_main.o Item_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Item.o Item_test.cc -o item_test
	
matrix_test: Matrix_Map.o test_main.o Matrix_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Matrix_Map.o Matrix_test.cc -o matrix_test
tbtest:
	$(CCC) $(CCFLAGS) tangenttest.cpp -o tbtest.exe -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
	
all_test: Bomb.o Explosion.o Item.o Game.o Character.o Matrix_Map.o test_main.o Bomb_test.cc Explosion_test.cc Game_test.cc Item_test.cc Character_test.cc Matrix_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Bomb.o Explosion.o Game.o Character.o Item.o Matrix_Map.o Bomb_test.cc Explosion_test.cc Game_test.cc Item_test.cc Character_test.cc Matrix_test.cc -o all_test
	
# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)

Bomb.o: Bomb.h Bomb.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Bomb.cc
	
Explosion.o: Explosion.h Explosion.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Explosion.cc

Game.o: Game.h Game.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Game.cc
	
Main_game.o: Main_game.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Main_game.cc
	
Character.o: Character.h Character.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Character.cc
	
Item.o: Item.h Item.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Item.cc
	
Matrix_Map.o: Matrix_Map.h Matrix_Map.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Matrix_Map.cc
	
test_main.o: test_main.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c test_main.cc	
	
Timer.o: Timer.h Timer.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Timer.cc
	
# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	del -f *.o *.exe

# Se upp vid eventuell ändring, '*' får absolut inte finnas för sig!!!
#
# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan flaggan '-i', används. 
