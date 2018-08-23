#include "stdafx.h"

#include "Render.h"

#include <fstream>
#include <sstream>

namespace Render {

	GLuint loadShaders(const char *vertex_file_path, const char *fragment_file_path) {

		// Create the shaders
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		// Read the Vertex Shader code from the file
		std::string vertexShaderCode;
		std::ifstream vertexShaderStream(vertex_file_path, std::ios::in);

		if (vertexShaderStream.is_open()) {

			std::stringstream sstr;

			sstr << vertexShaderStream.rdbuf();
			vertexShaderCode = sstr.str();

			vertexShaderStream.close();

		} else {

			std::cout << "[-] IFStream: " << vertex_file_path << " failed to load\n";

			return NULL;

		}

		// Read the Fragment Shader code from the file
		std::string fragmentShaderCode;
		std::ifstream fragmentShaderStream(fragment_file_path, std::ios::in);

		if (fragmentShaderStream.is_open()) {

			std::stringstream sstr;

			sstr << fragmentShaderStream.rdbuf();
			fragmentShaderCode = sstr.str();

			fragmentShaderStream.close();

		}

		GLint result = GL_FALSE;
		int infoLogLength;

		// Compile Vertex Shader
		std::cout << "[+] Compiling shader " << vertex_file_path << "\n";
		char const *vertexSourcePointer = vertexShaderCode.c_str();

		glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL); //Add source
		glCompileShader(vertexShaderID); //Compile shader

		///* Comment out after testing (test for errors)
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0) {

			std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);

			glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
			std::cout << "[-] GLSL: Vertex Shader failed to compile\n" << vertexShaderErrorMessage[0] << "\n";

		}

		// Compile Vertex Shader
		std::cout << "[+] Compiling shader " << fragment_file_path << "\n";
		char const *fragmentSourcePointer = fragmentShaderCode.c_str();

		glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL); //Add source
		glCompileShader(fragmentShaderID); //Compile shader

		///* Comment out after testing (test for errors)
		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0) {

			std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);

			glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
			std::cout << "[-] GLSL: Fragment Shader failed to compile\n" << fragmentShaderErrorMessage[0] << "\n";

		}

		// Link the program
		std::cout << "[+] GLSL: Linking program";

		GLuint programID = glCreateProgram();

		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);

		glLinkProgram(programID);

		// Check the program
		glGetProgramiv(programID, GL_LINK_STATUS, &result);
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0) {

			std::vector<char> programErrorMessage(infoLogLength + 1);

			glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
			std::cout << "[-] GLSL: Shader Program failed to link\n" << programErrorMessage[0] << "\n";

		}

		glDetachShader(programID, vertexShaderID);
		glDetachShader(programID, fragmentShaderID);

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return programID;

	}


};
