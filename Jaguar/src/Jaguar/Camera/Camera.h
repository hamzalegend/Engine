#pragma once
#include "Jaguar/Math.h"


class Camera
{
public:
	Camera(Vector2 WindowDimentions);
	~Camera();

public:
    Vector3 Position = Vector3(0.0f, 0.0f, 3.0f);;
    Vector3 Rotation = Vector3(0,-90.0f, 0); // x:pich, y:yaw, z:roll
    // Vector3 direction;
    Vector2 WindowDimentions;

    Mat4 GetViewMatrix();
    Mat4 GetProjectionMatrix();

    Mat4 view;
    Mat4 projection;
    // glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    // glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    // glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
     
    // static void SetMainCamera(Camera* cam) { s_MainCam = cam; }
    // static Camera* GetMainCamera(){ return s_MainCam; } // TODO::
    
    // void Camera::SetMainCamera(Camera* cam) 

    // static Camera* s_MainCam;

    

private:    

    float NearPlane = 0.1f;
    float FarPlane = 100.0f;

    float lastX = 400, lastY = 300;
    bool firstMouse = true;
};
