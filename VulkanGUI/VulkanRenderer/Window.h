#pragma once
#include<vulkan/vulkan.h>
#include<GLFW/glfw3.h>
#define GLFW_INCLUDE_VULKAN

#include <string>
#include <stdexcept>

namespace Vulkanrenderer
{
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		~Window();

		VkSurfaceKHR createSurface(VkInstance instance);

		// non copyable and non movable
		Window(const Window&) = delete;					
		Window& operator=(const Window&) = delete;		

		bool shouldClose();
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
		bool wasWindowResized() { return framebufferResized; }
		void resetWindowResizedFlag() { framebufferResized = false; }
	private:

		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

		GLFWwindow* window;
		int width;
		int height;
		std::string title;
		bool framebufferResized = false;
	};

}

