#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderEyelightTextured.h"
#include "ShaderPhong.h"
#include "PrimTriangle.h"
#include "PrimTriangleSmooth.h"
#include "PrimTriangleSmoothTextured.h"

#include <fstream> 


void CScene::ParseOBJ(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (file.is_open()) {
		std::cout << "Parsing OBJFile : " << fileName << std::endl;

		std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 0.5f, 0));
		std::vector<Vec3f> vVertexes;
		std::vector<Vec3f> vNormals;
		std::vector<Vec2f> vTextures;
		
		std::string line;

		for (;;) {
			if (!getline(file, line)) break;
			std::stringstream ss(line);
			getline(ss, line, ' ');
			if (line == "v") {
				Vec3f v;
				for (int i = 0; i < 3; i++) ss >> v.val[i];
				// std::cout << "Vertex: " << v << std::endl;
				vVertexes.emplace_back(v);
			}
			else if (line == "f") {
				Vec3i f;
				Vec3i f1;
				Vec3i f2;
				char c;
				for (int i = 0; i < 3; i++)
				{
					ss >> f.val[i] >> c >> f1.val[i] >> c >> f2.val[i];
				}
				// std::cout << "Face: " << f << std::endl;
				Add(std::make_shared<CPrimTriangleSmooth>(vVertexes[f.val[0] - 1], vVertexes[f.val[1] - 1], vVertexes[f.val[2] - 1], vNormals[f2.val[0] - 1], vNormals[f2.val[1] - 1], vNormals[f2.val[2] - 1], pShader));
			}
			else if (line == "vn")
			{
				Vec3f vectorN;
				for (int i = 0; i < 3; i++)
				{
					ss >> vectorN.val[i];
				}
				vNormals.emplace_back(vectorN);
			}
			else if (line == "vt")
			{
				Vec2f texCoords;
				for (int i = 0; i < 2; i++)
				{
					ss >> texCoords.val[i];
				}
				vTextures.emplace_back(texCoords);
			}
			else {
				std::cout << "Unknown key [" << line << "] met in the OBJ file" << std::endl;
			}
		}

		file.close();
		std::cout << "Finished Parsing" << std::endl;
	} else
		std::cout << "ERROR: Can't open OBJFile" << std::endl;
}
