#pragma once
#include "Device.h"
#include "Window.h"
#include "Pipeline.h"
#include "SwapChain.h"

namespace Vulkanrenderer
{
	class VulkanRenderer
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;


		VulkanRenderer();
		
		~VulkanRenderer();

		VulkanRenderer(const VulkanRenderer&) = delete;
		VulkanRenderer& operator=(const VulkanRenderer&) = delete;

		void renderLoop();

	private:
		void loadObjects();
		

		void renderObjects();

		Window window{ WIDTH, HEIGHT, "Vulkan Tutorial" };
		Device Device{ window };
		std::unique_ptr<SwapChain> SwapChain;
		std::unique_ptr<Pipeline> Pipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
		//std::vector<GameObject> gameObjects;
		
	};
}


