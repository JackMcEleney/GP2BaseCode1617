#include "MyGame.h"

struct Vertex
{
	float x, y, z;
};
	
	const std::string ASSET_PATH = "assets";
	const std::string SHADER_PATH = "/shaders";

MyGame::MyGame()
{
	m_VBO = 0;
	m_VAO = 0;
}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	GameApplication::initScene();
	Vertex verts[] = 
	{
		{-0.5f, -0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f}
	};
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), verts, GL_STATIC_DRAW);
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		NULL);

	GLuint vertexShaderProgram = 0;
	std::string vsPath = ASSET_PATH + SHADER_PATH + "/simpleVS.glsl";
	vertexShaderProgram = loadShaderFromFile(vsPath, VERTEX_SHADER);

	GLuint fragmentShaderProgram = 0;
	std::string fsPath = ASSET_PATH + SHADER_PATH + "/simpleFS.glsl";
	fragmentShaderProgram = loadShaderFromFile(fsPath, FRAGMENT_SHADER);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertexShaderProgram);
	glAttachShader(m_ShaderProgram, fragmentShaderProgram);
	glLinkProgram(m_ShaderProgram);
	checkForLinkErrors(m_ShaderProgram);
	logShaderInfo(m_ShaderProgram);
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);
}

void MyGame::destroyScene()
{
	GameApplication::destroyScene();
	glDeleteProgram(m_ShaderProgram);
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	
}

void MyGame::render()
{
	GameApplication::render();
}

void MyGame::update()
{
	GameApplication::update();
}