OBJ = Camera.o Game.o GameObject.o GameWorld.o Main.o Shader.o Shape.o Texture.o MainMenu.o GamePage.o\
	Bullet.o Enemy.o
PROJ_NAME = SpaceInvaderOpenGL
LIBS = -lglfw -ldl -lpthread -lX11 -lGLEW -lm -lGL -lSOIL

all: $(OBJ)
	gcc -o $(PROJ_NAME) $(OBJ) $(LIBS) -Wall
clean:
	rm -f $(OBJ) $(PROJ_NAME)

Camera.o: ../Camera.h ../Camera.c
	gcc -c ../Camera.c

Game.o: ../Game.h ../Game.c ../GameWorld.h ../GameObject.h
	gcc -c ../Game.c

GameObject.o: ../GameObject.h ../GameObject.c ../Shape.h ../Shader.h ../Texture.h
	gcc -c ../GameObject.c

GameWorld.o: ../GameWorld.h ../GameWorld.c ../GameObject.h
	gcc -c ../GameWorld.c

Main.o: ../Main.c
	gcc -c ../Main.c

Shader.o: ../Shader.h ../Shader.c 
	gcc -c ../Shader.c

Shape.o: ../Shape.h ../Shape.c
	gcc -c ../Shape.c

Texture.o: ../Texture.h ../Texture.c
	gcc -c ../Texture.c

MainMenu.o: ../SpaceInvaderGame/MainMenu.h ../SpaceInvaderGame/MainMenu.c ../GameWorld.h
	gcc -c ../SpaceInvaderGame/MainMenu.c

GamePage.o: ../SpaceInvaderGame/GamePage.h ../SpaceInvaderGame/GamePage.c ../GameWorld.h
	gcc -c ../SpaceInvaderGame/GamePage.c

Bullet.o: ../SpaceInvaderGame/Bullet.h ../SpaceInvaderGame/Bullet.c ../GameObject.h
	gcc -c ../SpaceInvaderGame/Bullet.c

Enemy.o: ../SpaceInvaderGame/Enemy.h ../SpaceInvaderGame/Enemy.c ../GameObject.h
	gcc -c ../SpaceInvaderGame/Enemy.c
