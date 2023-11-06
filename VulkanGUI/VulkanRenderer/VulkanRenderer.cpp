#include "VulkanRenderer.h"
namespace Vulkanrenderer
{
	VulkanRenderer::VulkanRenderer()
	{
		
		
		
	}

	VulkanRenderer::~VulkanRenderer()
	{
		
	}

	void VulkanRenderer::renderLoop()
	{
		while (!window.shouldClose()) {
			glfwPollEvents();
		}

		vkDeviceWaitIdle(Device.getDevice());
	}


}

