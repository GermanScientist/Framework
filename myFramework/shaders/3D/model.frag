#version 120

// Interpolated values from the vertex shaders
varying vec2 UV;
varying vec3 Position_worldspace;
varying vec3 Normal_cameraspace;
varying vec3 EyeDirection_cameraspace;
varying vec3 LightDirection_cameraspace;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;

void main(){

	//Light emission properties
	//You probably want to put them as uniforms
	vec3 LightColor = vec3(1,1,1);
	float LightPower = 50.0f;
	
	//Material properties
	vec3 MaterialDiffuseColor = texture2D(myTextureSampler, UV).rgb;
	vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = vec3(0.3,0.3,0.3);

	//Distance to the light
	float distance = length(LightPosition_worldspace - Position_worldspace);

	//Normal of the computed fragment, in camera space
	vec3 normal = normalize(Normal_cameraspace);
	
	//Direction of the light (from the fragment to the light)
	vec3 lightDirection = normalize(LightDirection_cameraspace);
	
	//Clamped cosine of the angle between the normal and the light direction above 0, 
	//Light is at the vertical of the triangle = 1
	//Light is perpendicular to the triangle = 0
	//Light is behind the triangle = 0
	float cosTheta = clamp(dot(normal, lightDirection), 0,1);
	
	//Eye vector (towards the camera)
	vec3 EyeDirection = normalize(EyeDirection_cameraspace);
	
	//Direction in which the triangle reflects the light
	vec3 ReflectionDirection = reflect(-lightDirection, normal);
	
	//Clamped cosine of the angle between the Eye vector and the Reflect vector to 0,
	//Looking into the reflection = 1, Looking elsewhere = < 1
	float cosAlpha = clamp(dot(EyeDirection, ReflectionDirection), 0,1);
	
	//Ambient: simulates indirect lighting
	//Diffuse: "color" of the object
	//Specular: reflective highlight, like a mirror
	gl_FragColor.rgb = MaterialAmbientColor + MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance) + MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5) / (distance*distance);

}