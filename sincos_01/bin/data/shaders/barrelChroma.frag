// Barrel distortion
// based on https://www.shadertoy.com/view/XdfGzH


uniform sampler2DRect tex;
uniform float time;
float amount = 300.;
uniform vec2 resolution;
uniform vec2 mouse;
float move;


const vec4 color = vec4(0.527, 0.250, 0.137, 1.0);

void main(void)
{
	float aspectRatio = resolution.y / resolution.x;

//	vec2 uv = gl_FragCoord.xy / resolution.xy;
//	uv += 0.5+ (uv-0.5)*(0.9 + 0.01*sin(time));

	vec2 st = gl_TexCoord[0].st;


	vec2 screenSpaceCoord = vec2((gl_FragCoord.x  / resolution.x  - 0.5) , (gl_FragCoord.y / resolution.y  - 0.5) * aspectRatio ) * 2.0;
	 
	float distanceOrigin = length(screenSpaceCoord);
	
	float exposure = pow(distanceOrigin, 1.0);
	vec3 rgb = color.xyz / exposure ;

	st *= pow(rgb.r,0.2) ;

	vec4 col = texture2DRect(tex, st);

	float a = 1.0;
	gl_FragColor = vec4(col.rgb, a);
} 



