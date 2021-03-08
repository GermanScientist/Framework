#version 120

// Input vertex data, different for all executions of this shader.
attribute vec3 vertexPosition_modelspace;
attribute vec2 vertexUV;
attribute vec3 vertexNormal_modelspace;

// Output data ; will be interpolated for each fragment.
varying vec2 UV;
varying vec3 Position_worldspace;
varying vec3 Normal_cameraspace;
varying vec3 EyeDirection_cameraspace;
varying vec3 LightDirection_cameraspace;
varying vec4 ShadowCoord;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 LightInvDirection_worldspace;
uniform mat4 DepthBiasMVP;


void main(){

	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
	
	ShadowCoord = DepthBiasMVP * vec4(vertexPosition_modelspace,1);
	
	// Position of the vertex, in worldspace : M * position
	Position_worldspace = (M * vec4(vertexPosition_modelspace,1)).xyz;
	
	// Vector that goes from the vertex to the camera, in camera space.
	// In camera space, the camera is at the origin (0,0,0).
	EyeDirection_cameraspace = vec3(0,0,0) - ( V * M * vec4(vertexPosition_modelspace,1)).xyz;

	// Vector that goes from the vertex to the light, in camera space
	LightDirection_cameraspace = (V*vec4(LightInvDirection_worldspace,0)).xyz;
	
	// Normal of the the vertex, in camera space
	Normal_cameraspace = ( V * M * vec4(vertexNormal_modelspace,0)).xyz; // Only correct if ModelMatrix does not scale the model ! Use its inverse transpose if not.
	
	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}

