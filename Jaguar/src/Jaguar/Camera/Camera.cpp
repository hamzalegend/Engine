#include "Camera.h"

Camera::Camera(Vector2 WinDimentions)
    :projection(Mat4(1.0f)), view(Mat4(1.0f)), WindowDimentions(WinDimentions)
{
}

Camera::~Camera()
{
}

Mat4 Camera::GetViewMatrix()
{
    view = glm::translate(Mat4(1.0), Position);
	return view;
}
Mat4 Camera::GetProjectionMatrix()
{
    projection = glm::perspective(glm::radians(45.0f), (float)WindowDimentions.x / (float)WindowDimentions.y, NearPlane, FarPlane);
    return projection;
}
