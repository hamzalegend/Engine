#include "Camera.h"
#include <Jaguar/Log/log.h>

Camera::Camera(Vector2 WinDimentions)
    :projection(Mat4(1.0f)), view(Mat4(1.0f)), WindowDimentions(WinDimentions)
{
    // if (s_MainCam == NULL)
    //     s_MainCam = this;
    Position = Vector3(0.0f, 0.0f, 3.0f);
    // s_MainCam = this;
    
}

Camera::~Camera()
{
}

Mat4 Camera::GetViewMatrix()
{
    view = Mat4(1.0f);
    view = glm::translate(Mat4(1.0), Position); //placeholder // TODO ::
    // view = glm::rotate(view, Rotation.x, Vector3(1,0,0));
    // view = glm::rotate(view, Rotation.y, Vector3(0,1,0));
    // view = glm::rotate(view, Rotation.z, Vector3(0,0,1));
    // view = glm::inverse(view);
	return view;


    // view = Mat4(1.0f);
    // view = glm::translate(Mat4(1.0), Position) * glm::rotate(view, Rotation.x, Vector3(1, 0, 0)) * glm::rotate(view, Rotation.y, Vector3(0, 1, 0)) * glm::rotate(view, Rotation.z, Vector3(0, 0, 1));
    // 
    // view = glm::inverse(view);
	// return view;

    // x:pich, y:yaw, z:roll
}
Mat4 Camera::GetProjectionMatrix()
{
    // projection = glm::perspective(glm::radians(45.0f), (float)WindowDimentions.x / (float)WindowDimentions.y, NearPlane, FarPlane);
    projection = glm::perspective(glm::radians(45.0f), (float)600/ (float)600, NearPlane, FarPlane); // placedholder // TODO ::
    return projection;
}
