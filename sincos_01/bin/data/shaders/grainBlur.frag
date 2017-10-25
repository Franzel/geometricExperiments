#version 120

uniform float time;
uniform sampler2DRect tex;
uniform vec2 resolution;

int ITER = 32;
float SIZE = 16.;

void srand(vec2 a, out float r)
{
	r=sin(dot(a,vec2(1233.224,1743.335)));
}

float rand(inout float r)
{
	r=fract(3712.65*r+0.61432);
	return (r-0.5)*2.0;
}

void main(void)
{
	
    vec2 coord = gl_TexCoord[0].st;
    vec4 color = texture2DRect(tex,coord);
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    
	float p=SIZE/resolution.y*(sin(time/2.0)+1.0);
	vec4 c=vec4(0.0);
	float r;
	srand(uv, r);
	vec2 rv;
	
	for(int i=0;i<ITER;i++)
	{
		rv.x=rand(r);
		rv.y=rand(r);
		c+=texture2DRect(tex,-uv+rv*p)/float(ITER);
	}
    c = color;
	gl_FragColor = c;
}