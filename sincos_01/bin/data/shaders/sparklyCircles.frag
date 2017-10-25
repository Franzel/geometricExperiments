// Based on https://www.shadertoy.com/view/XsXXDn

// http://www.pouet.net/prod.php?which=57245


#version 120

uniform float time;
uniform vec2 resolution;
uniform vec2 mouse;

int depth = 3;


void main(){
	vec3 c;
	float l,z=time;
    
	for(int i=0;i<depth;i++) {
		vec2 uv,p=gl_FragCoord.xy/resolution;
        
		uv=p;
		p-=.5;
        
		p.x*=resolution.x/resolution.y;
		z+=.07;
        
		l=length(p);
        
		uv+=p/l*(cos(z)+1.)*abs(sin(l*9.-z*2.));
        
		c[i]=.01/length(abs(mod(uv,1.)-.5));
	}
	gl_FragColor=vec4(c/l,1.);
}