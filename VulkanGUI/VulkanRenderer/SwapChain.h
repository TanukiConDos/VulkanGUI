#pragma once
#include <vulkan/vulkan.hpp>
#include"Device.h"

namespace Vulkanrenderer
{

	class SwapChain
	{
	public:

		SwapChain(Device& device, Window& window);

		~SwapChain();

		// Not copyable or movable
		SwapChain(const SwapChain&) = delete;
		SwapChain& operator=(const SwapChain&) = delete;
		SwapChain(SwapChain&&) = delete;
		SwapChain& operator=(SwapChain&&) = delete;


	private:
		VkRenderPass renderPass;
		VkPipelineLayout pipelineLayout;

		VkSwapchainKHR swapChain;
		Device& device;
		Window& window;

		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

	};
}


