R(" 

#version 410 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D aTexture;

void main() {

	FragColor = texture(aTexture, texCoord);

}


")