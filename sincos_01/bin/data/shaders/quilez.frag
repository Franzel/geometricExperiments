// Created by inigo quilez - iq/2013
// License Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.

uniform sampler2D tex;
uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    vec2 m = -1.0 + 2.0 * mouse.xy / resolution.xy;
    
    float a1 = atan(p.y-m.y,p.x-m.x);
    float r1 = sqrt(dot(p-m,p-m));
    float a2 = atan(p.y+m.y,p.x+m.x);
    float r2 = sqrt(dot(p+m,p+m));
    
    vec2 uv;
    uv.x = 0.2*time + (r1-r2)*0.25;
    uv.y = asin(sin(a1-a2))/3.1416;
	
    
    vec3 col = texture2D( tex, 0.125*uv ).zyx;
    
    float w = exp(-15.0*r1*r1) + exp(-15.0*r2*r2);
    
    w += 0.25*smoothstep( 0.93,1.0,sin(256.0*uv.x));
    w += 0.25*smoothstep( 0.93,1.0,sin(256.0*uv.y));
	
    gl_FragColor = vec4(col+w,1.0);
}