#include "Camera.h"

#include "Jaguar/Renderer/Renderer.h"
namespace Jaguar
{
	void Camera::SetFOV(float fov)
	{
		FOV = fov;
		if (RendererAPI::Get_API() == RendererAPI::API::OpenGL)
		{
			m_projection = glm::perspective(glm::radians(FOV), m_WindowDimetions.x / m_WindowDimetions.y, m_NearPlane, m_FarPlane);
		}
	}

	Mat4 Camera::GetProjectionMatrix()
	{
		return m_projection;
	}

	Mat4 Camera::GetViewMatrix()
	{
        // glm::vec3 direction;
        // direction.x = cos(glm::radians(Rotation.y)) * cos(glm::radians(Rotation.x));
        // direction.y = sin(glm::radians(Rotation.x));
        // direction.z = sin(glm::radians(Rotation.y)) * cos(glm::radians(Rotation.x));
        // Front = glm::normalize(direction);

        m_view = glm::lookAt(Position, Position + Front, WorldUp);
		return m_view;
	}

	

    Camera::Camera(Vector2 windowdimentions, float fov)
        :FOV(fov), m_WindowDimetions(windowdimentions)
    {
        if (RendererAPI::Get_API() == RendererAPI::API::OpenGL)
        {
           // m_projection = glm::perspective(glm::radians(FOV), m_WindowDimetions.x / m_WindowDimetions.y, 0.1f, 100.0f);
        }        
    }

    Camera::~Camera()
	{
	}
}

    
/*


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
   
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
   
    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(Position, Position + Front, Up);
    }

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (direction == FORWARD)
            Position += Front * velocity;
        if (direction == BACKWARD)
            Position -= Front * velocity;
        if (direction == LEFT)
            Position -= Right * velocity;
        if (direction == RIGHT)
            Position += Right * velocity;
    }

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }

private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up = glm::normalize(glm::cross(Right, Front));
    }
};*/