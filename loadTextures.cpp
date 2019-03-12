#ifndef LOAD_TEXTURES
#define LOAD_TEXTURES

#include "includes.h"
//#include "globals.h"

//GLuint textureID[1];

void loadTextures(){

    extern GLuint textureID[1];
	unsigned char* image;
	int width, height;

	glGenTextures(1, &textureID[0]);
    glBindTexture(GL_TEXTURE_2D, textureID[0]);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	cout << &width << &height << endl;
	image = SOIL_load_image("./textures/floor_pattern_square.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	glGenerateMipmap(GL_TEXTURE_2D);
	
	SOIL_free_image_data(image);
}
#endif
