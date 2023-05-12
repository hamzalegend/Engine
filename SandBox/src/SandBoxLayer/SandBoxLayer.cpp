#include "SandBoxLayer.h"

namespace Jaguar
{

	std::vector<float> Verticess = {
		// positions          // colors                // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	std::vector<unsigned int> indicess = {
		0, 1, 3,
		1, 2, 3,
	};

	// Mesh processMesh(aiMesh* mesh, const aiScene* scene)
	// {
	// 	Mesh Tmesh;
	// 
	// 	// verticies
	// 	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	// 	{
	// 		Tmesh.Vertices.push_back(mesh->mVertices[i].x);
	// 		Tmesh.Vertices.push_back(mesh->mVertices[i].y);
	// 		Tmesh.Vertices.push_back(mesh->mVertices[i].z);
	// 
	// 		JR_CORE_INFO("v ({0}, {1}, {2})", mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
	// 	}
	// 	// indicies
	// 	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	// 	{
	// 		aiFace face = mesh->mFaces[i];
	// 		for (unsigned int j = 0; j < face.mNumIndices; j++)
	// 			Tmesh.indices.push_back(face.mIndices[j]);
	// 		JR_CORE_INFO("I {0}", face.mIndices[i]);
	// 	}
	// 
	// 	
	// 	return Tmesh;
	// }

	void SandBoxLayer::OnAttach()
	{
	   JR_CORE_INFO("start()");
	   {
		   e.GetComponent<TransformComponent>().Transform = Mat4(1.0f);
		   e.AddComponent<MeshRendererComponent>();
		   e.GetComponent<MeshRendererComponent>().mesh.Vertices = Verticess;
		   e.GetComponent<MeshRendererComponent>().mesh.indices = indicess;
		   e.GetComponent<MeshRendererComponent>().mesh.color = Vector4(25, 52, 63, 0);
		   camera.AddComponent<CameraComponent>();
		   camera.GetComponent<CameraComponent>().cam = new Camera();
		   Camera* cam = camera.GetComponent<CameraComponent>().cam;
		   cam->Transform = &camera.GetComponent<TransformComponent>();
		   cam->Transform->Position.z = -4;
	   }
	   
	   // Assimp::Importer importer;
	   // const aiScene* scene = importer.ReadFile("src/models/cube.fbx", aiProcess_Triangulate | aiProcess_FlipUVs);
	   // aiNode* node = scene->mRootNode;
	   // // preces node()
	   //
		//    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		//    {
		// 	   JR_CORE_ERROR("ERROR::ASSIMP::{0}", importer.GetErrorString());
		// 	   return;
		//    }
		//    // process all the node's meshes (if any)
		//    for (unsigned int i = 0; i < node->mNumMeshes; i++)
		//    {
		// 	   aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		// 	   processMesh(mesh, scene);
		//    }
	   //
	}
	void SandBoxLayer::OnUpdate(float deltaTime)
	{
		// JR_CORE_INFO("Update);
		// Move Player
		{
			TransformComponent& camTransform = camera.GetComponent<TransformComponent>();
			if (Input::GetKey(GLFW_KEY_D))
			{
				camTransform.Position.x -= deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_A))
			{
				camTransform.Position.x += deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_W))
			{
				camTransform.Position.z += deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_S))
			{
				camTransform.Position.z -= deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_E))
			{
				camTransform.Position.y -= deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_Q))
			{
				camTransform.Position.y += deltaTime * 10;
			}
		}

		scene->OnUpdate(deltaTime);

	}
	
	void SandBoxLayer::OnEvent(Jaguar::Event& event)
	{
	}

	SandBoxLayer::~SandBoxLayer()
	{
	}
}
