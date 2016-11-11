# Diagnosmeddelanden från kompilatorn (g++) filtreras av gccfilter.
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++14 -Wpedantic -Wall -Wextra -Werror -Weffc++

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = Character.o Item.o Bomb.o Matrix_Map.o Game.o Main_game.o Explosion.o

# Huvudmål - skapas med kommandot 'make' eller 'make boombox'.
boombox: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o boombox $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
boombox.o: boombox.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c boombox.cc

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
	
# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf boombox *~

# Se upp vid eventuell ändring, '*' får absolut inte finnas för sig!!!
#
# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan flaggan '-i', används. 
