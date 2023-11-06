#pragma once
#include<vulkan/vulkan.hpp>

#include<fstream>

namespace Vulkanrenderer
{
	class Pipeline
	{
	public:

		Pipeline(VkDevice& device);

		~Pipeline();

		// Not copyable or movable
		Pipeline(const Pipeline&) = delete;
		Pipeline& operator=(const Pipeline&) = delete;
		Pipeline(Pipeline&&) = delete;
		Pipeline& operator=(Pipeline&&) = delete;


	private:

		VkDevice& device;
		VkShaderModule vertexShader;
		VkShaderModule fragmentShader;
		VkPipelineLayout pipelineLayout;

		VkShaderModule createShaderModule(const std::vector<char>& code);
		std::vector<char> readFile(const std::string& filename);

	};


}
