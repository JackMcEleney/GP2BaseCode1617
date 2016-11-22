#include "MyGame.h"

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";

MyGame::MyGame()
{
	m_TestObject = nullptr;
}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	
	Vertex verts[] = {
		{vec3(-2.5f, -2.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,3.0f)},
		{vec3(2.5f, -2.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,3.0f)},
		{vec3(-2.5f,  2.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,0.0f)},
		//{vec3(-0.5f, 0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,0.0f)},
		{vec3(2.5f, 2.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,0.0f)},
		//{vec3(0.5f,  -0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,3.0f)}
	};

	int Indices[] = {0, 1, 2, 2, 3, 1};

	m_TestObject = new GameObject();

	string vsPath = ASSET_PATH + SHADER_PATH + "/simpleVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/textureFS.glsl";
	m_TestObject->loadShaders(vsPath, fsPath);

	//lets load texture
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";
	m_TestObject->loadTexture(texturePath);

	m_TestObject->copyVertexData(verts, 4, Indices, 6);	
}

void MyGame::destroyScene()
{
	if (m_TestObject)
	{
		m_TestObject->onDestroy();
		delete m_TestObject;
		m_TestObject = nullptr;
	}
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 100.0f);
	m_ViewMatrix = lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m_ModelMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -0.2f));

	m_TestObject->onUpdate();
}

void MyGame::render()
{
	GameApplication::render();
	m_TestObject->onRender(m_ViewMatrix, m_ProjMatrix);
}
