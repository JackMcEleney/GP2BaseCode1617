#include "MyGame.h"

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";
const std::string MODEL_PATH = "/models";

MyGame::MyGame()
{
	m_TestObject = nullptr;
	m_ModelObject = nullptr;
}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	m_TestObject = new GameObject();
	m_ModelObject = new GameObject();
	
	string vsPath = ASSET_PATH + SHADER_PATH + "/lightVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/lightFS.glsl";
	
	//m_TestObject->loadShaders(vsPath, fsPath);

	//lets load texture
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";
	//m_TestObject->loadTexture(texturePath);

	//m_TestObject->copyVertexData(verts, 4, Indices, 6);	
	

	string modelPath = ASSET_PATH + MODEL_PATH + "/utah-teapot.fbx";
	m_ModelObject = loadModelFromFile(modelPath);
	m_ModelObject->loadShaders(vsPath, fsPath);

	m_CameraPosition = vec3(0.0f, 0.0f, 100.0f);

	m_Light = shared_ptr<Light>(new Light());
	m_Light->DiffuseColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SpecularColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->Direction = vec3(0.0f, 0.0f, -1.0f);
	m_AmbientLightColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

void MyGame::destroyScene()
{
	if (m_TestObject)
	{
		m_TestObject->onDestroy();
		delete m_TestObject;
		m_TestObject = nullptr;
	}

	if (m_ModelObject)
	{
		m_ModelObject->onDestroy();
		delete m_ModelObject;
		m_ModelObject = nullptr;
	}
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 1000.0f);
	m_ViewMatrix = lookAt(m_CameraPosition, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m_ModelObject->onUpdate();
}

void MyGame::render()
{
	GameApplication::render();
	GLuint currentShader = m_ModelObject->getShaderProgram();

	GLint ambientLightColourLocation = glGetUniformLocation(currentShader, "ambientLightColour");
	glUniform4fv(ambientLightColourLocation, 1, value_ptr(m_AmbientLightColour));

	GLint diffuseLightColourLocation = glGetUniformLocation(currentShader, "diffuseLightColour");
	glUniform4fv(diffuseLightColourLocation, 1, value_ptr(m_Light->DiffuseColour));

	GLint specularLightColourLocation = glGetUniformLocation(currentShader, "specularLightColour");
	glUniform4fv(specularLightColourLocation, 1, value_ptr(m_Light->SpecularColour));

	GLint lightDirectionLocation = glGetUniformLocation(currentShader, "lightDirection");
	glUniform3fv(lightDirectionLocation, 1, value_ptr(m_Light->Direction));

	GLint cameraPositionLocation = glGetUniformLocation(currentShader, "cameraPos");
	glUniform3fv(cameraPositionLocation, 1, value_ptr(m_CameraPosition));

	m_ModelObject->onRender(m_ViewMatrix, m_ProjMatrix);
}
