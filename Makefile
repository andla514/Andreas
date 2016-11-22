# Filkataloger där andra delar av programet finns.
SFML = ../SFML

# Diagnosmeddelanden från kompilatorn (g++) filtreras av gccfilter.
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++14 -Wpedantic -Wall 
#-Weffc++ -Werror -Wextra 

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
EXTRA_TAGS += -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg

# Objektkodsmoduler som ingår i den kompletta boombox.

OBJECTS = Main.o Bomb.o Matrix_Map.o Character.o Game.o Main_game.cc Explosion.o Timer.o Item.o

#OBJECTS = Character.o Item.o Bomb.o Matrix_Map.o Game.o Main_game.o Explosion.o Timer.o


# Huvudmål - skapas med kommandot 'make' eller 'make boombox'.
boombox: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) $(OBJECTS) -o boombox $(EXTRA_TAGS)

explosion_test: Explosion.o test_main.o Game.o Item.o Bomb.o Character.o Matrix_Map.o Timer.o Explosion_test.cc 
	$(CCC) $(CPPFLAGS) $(CCFLAGS) Explosion.o test_main.o Game.o Item.o Bomb.o Character.o Matrix_Map.o Timer.o Explosion_test.cc -o explosion_test $(EXTRA_TAGS)
	
bomb_test: Bomb.o test_main.o Game.o Item.o Explosion.o Character.o Matrix_Map.o Timer.o Bomb_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Bomb.o Game.o Item.o Explosion.o Character.o Matrix_Map.o Timer.o Bomb_test.cc -o bomb_test $(EXTRA_TAGS)

game_test: test_main.o Matrix_Map.o Game.o Timer.o Game_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Matrix_Map.o Game.o Timer.o Game_test.cc -o game_test $(EXTRA_TAGS)
	
character_test: Character.o Game.o Matrix_Map.o Bomb.o Item.o Explosion.o test_main.o  Character_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) Game.o Character.o Matrix_Map.o Bomb.o Item.o Explosion.o test_main.o Character_test.cc -o character_test $(EXTRA_TAGS)
	
item_test: test_main.o Bomb.o Matrix_Map.o Character.o Game.o Explosion.o Timer.o Item.o Item_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Bomb.o Matrix_Map.o Character.o Game.o Explosion.o Timer.o Item.o Item_test.cc -o item_test $(EXTRA_TAGS)
	
matrix_test: Matrix_Map.o test_main.o Matrix_test.cc Timer.o
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Timer.o Matrix_Map.o Matrix_test.cc -o matrix_test $(EXTRA_TAGS)
	
tbtest:
	$(CCC) $(CCFLAGS) tangenttest.cpp -o tbtest.exe $(EXTRA_TAGS)
	
all_test: Bomb.o Explosion.o Item.o Game.o Character.o Matrix_Map.o test_main.o Bomb_test.cc Explosion_test.cc Game_test.cc Item_test.cc Character_test.cc Matrix_test.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Bomb.o Explosion.o Game.o Character.o Item.o Matrix_Map.o Bomb_test.cc Explosion_test.cc Game_test.cc Item_test.cc Character_test.cc Matrix_test.cc -o all_test
	
# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)

Bomb.o: Bomb.h Bomb.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Bomb.cc $(EXTRA_TAGS)
	
Explosion.o: Explosion.h Explosion.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Explosion.cc $(EXTRA_TAGS)

Game.o: Game.h Game.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Game.cc $(EXTRA_TAGS)
	
Main_game.o: Main_game.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Main_game.cc $(EXTRA_TAGS)
	
Main.o: Main.h Main.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Main.cc $(EXTRA_TAGS)
	
Character.o: Character.h Character.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Character.cc $(EXTRA_TAGS)
	
Item.o: Item.h Item.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Item.cc $(EXTRA_TAGS)
	
Matrix_Map.o: Matrix_Map.h Matrix_Map.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Matrix_Map.cc $(EXTRA_TAGS)
	
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
