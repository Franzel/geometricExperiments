// Hemisphere Light
// Francisco Zamorano, 2013
// Light computation based on example from The Orange Book

#version 120

// Receive uniforms from OF
uniform vec3 LightPosition;
uniform vec3 SkyColor;
uniform vec3 GroundColor;
uniform float time;

// Receive textures
uniform sampler2DRect tex; //base texture
uniform sampler2DRect tex2; //noise texture

uniform float spikiness;

//varying vec2 MultiTexCoordVarying; //use multitexCoord when not a rectangle
//varying vec2 TexCooord;

void main(){
    
    //-- Get coordinates
    vec2 coord = gl_MultiTexCoord0.xy; //get coord for each (this) vertex

    //-- Get colors for each vertex
    vec4 vertColor = texture2DRect(tex, coord);  //base texture color
    vec4 depthColor = texture2DRect(tex2, coord); //noise texture color
    
    //-- Hemisphere Light calculations
    vec3 ecPosition = vec3(gl_ModelViewMatrix * gl_Vertex);
    vec3 tnorm = normalize(gl_NormalMatrix * gl_Normal);
    vec3 lightVec = normalize(LightPosition - ecPosition);
    float costheta = dot(tnorm, lightVec);
    float a = 0.5 + 0.5 * costheta;
    vec4 lightColor = vec4(mix(GroundColor, SkyColor, a),1.0);
    
    //-- Explode vertices
    float expansion = tnorm.z; //get value from normal
    float displacement = mix(depthColor.r * 4, vertColor.r, 0.8) ; // use color for displacement from both textures
    vec4 newPos = ftransform();
    newPos += vec4(tnorm * displacement * (100*spikiness), 1.0);
    
    //-- Final vertex position
    gl_Position = newPos;
    
    //-- Colorize
    gl_FrontColor = mix(vertColor, lightColor, 0.2);
    gl_FrontColor.b += expansion;
    
//    gl_FrontColor = vertColor; //debug: tex1 color
//    gl_FrontColor = depthColor; //debug: tex2 color
    
}