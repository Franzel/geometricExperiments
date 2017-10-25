#version 120

uniform sampler2DRect tex;
uniform float time;
uniform vec2 resolution;
uniform vec2 mouse;

const vec4 color = vec4(0.527, 0.250, 0.137, 1.0);
float radius = 15.;

void main(){
    vec4 vertColor;
    vec4 vertTexCoord;
    float brightPassThreshold = 0.5;
    vec3 luminanceVector = vec3(0.2125, 0.7154, 0.0721);

    vec4 c = texture2DRect(tex, gl_Texcord[0].st);
    
    float luminance = dot(luminanceVector, c.xyz);
    luminance = max(0.0, luminance - brightPassThreshold);
    c.xyz *= sign(luminance);
    c.a = 1.0;
    
gl_FragColor = c;

}
