#include "Camera.h"
#include "Jaguar/Application.h"
#include <Jaguar/Log/log.h>
#include "Jaguar/Core.h"

namespace Jaguar
{    
    Camera::Camera(float Fov)
        :projection(Mat4(1.0f)), view(Mat4(1.0f)), FOV(Fov)
    {
        // if (s_MainCam == NULL)
        //     s_MainCam = this;
        // Position = Vector3(0.0f, 0.0f, 3.0f);
        // s_MainCam = this;
        
    }
    
    Camera::~Camera()
    {
    }

    void Camera::Update(float deltaTime)
    {
        // Direction.x = cos(glm::radians(Rotation.y)) * cos(glm::radians(Rotation.x));
        // Direction.y = sin(glm::radians(Rotation.x));
        // Direction.z = sin(glm::radians(Rotation.y)) * cos(glm::radians(Rotation.x));
        // Forward = glm::normalize(Direction);
    }
    
    Mat4 Camera::GetViewMatrix()
    {
        view = Mat4(1.0f);
        view = glm::translate(Mat4(1.0), Transform->Position); //placeholder // TODO ::
        // view = glm::rotate(view, Rotation.x, Vector3(1,0,0));
        // view = glm::rotate(view, Rotation.y, Vector3(0,1,0));
        // view = glm::rotate(view, Rotation.z, Vector3(0,0,1));
        // view = glm::inverse(view);
    	return view;
    
    
        // view = Mat4(1.0f);
        // view = glm::translate(Mat4(1.0), Position) * glm::rotate(view, Rotation.y, Vector3(-1, 0, 0)) * glm::rotate(view, Rotation.x, Vector3(0, 1, 0));
        // // 
        // view = glm::inverse(view);
    	// return view;
    
        // x:pich, y:yaw, z:roll
    }
    Mat4 Camera::GetProjectionMatrix()
    {
        Window* window = Application::Get().GetWindow();
        // projection = glm::perspective(glm::radians(45.0f), (float)WindowDimentions.x / (float)WindowDimentions.y, NearPlane, FarPlane);
        projection = glm::perspective(glm::radians(FOV), (float)window->Dimentions.x/ (float)window->Dimentions.y, NearPlane, FarPlane); // placedholder // TODO ::
        return projection;
    }
}
