#pragma once
#include<vulkan/vulkan.hpp>

#include<map>
#include <set>
#include "Window.h"

namespace Vulkanrenderer {

	struct QueueFamilyIndices {
		uint32_t graphicsFamily;
		uint32_t presentFamily;

		bool isComplete() {
			return graphicsFamily != NULL && presentFamily != NULL;
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};


	class Device
	{
	public:
		Device(Window& window);

		~Device();

		
		// Not copyable or movable
		Device(const Device&) = delete;
		Device& operator=(const Device&) = delete;
		Device(Device&&) = delete;
		Device& operator=(Device&&) = delete;

		VkDevice getDevice() { return device; }
		VkSurfaceKHR getSurface() { return surface; }
		SwapChainSupportDetails querySwapChainSupport();
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device = nullptr);
	private:

		VkInstance instance;
		Window& window;
		VkSurfaceKHR surface;

		VkPhysicalDevice physicalDevice;
		VkDevice device;

		VkQueue graphicQueue;
		VkQueue presentQueue;

		VkCommandPool commandPool;

		void createInstance();

		bool isDeviceSuitable(VkPhysicalDevice device);

		void pickPhysicalDevice(VkInstance instance);

		int rateDeviceSuitability(VkPhysicalDevice device);

		

		void createCommandPool();
	};

}

