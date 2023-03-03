#pragma once
#include "Jaguar/Math.h"
#include <Jaguar/Window/Window.h>

namespace Jaguar
{

    class Camera
    {
    public:
    	Camera(Window* window, float Fov=45);
    	~Camera();

        void Update(float deltaTime);
    
    public:
        Vector3 Position = Vector3(0.0f, 0.0f, 3.0f);;
        Vector3 Rotation = Vector3(0,-90.0f, 0); // x:pich, y:yaw, z:roll
        // Vector3 direction;
        Vector2 WindowDimentions;
    
        Mat4 GetViewMatrix();
        Mat4 GetProjectionMatrix();
    
        Mat4 view;
        Mat4 projection;
    
        // Vector3 Direction;
        // Vector3 Forward;
        
    
        // glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
        // glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        // glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
         
        // static void SetMainCamera(Camera* cam) { s_MainCam = cam; }
        // static Camera* GetMainCamera(){ return s_MainCam; } // TODO::
        
        // void Camera::SetMainCamera(Camera* cam) 
    
        // static Camera* s_MainCam;
    
        
    
    private:    

        Window* m_window;
        float FOV;
    
        float NearPlane = 0.1f;
        float FarPlane = 100.0f;
    
        // float lastX = 400, lastY = 300;
        // bool firstMouse = true;
    };
}