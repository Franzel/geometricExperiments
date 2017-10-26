// Barrel distortion
// Francisco Zamorano
// based on https://www.shadertoy.com/view/XdfGzH


uniform sampler2DRect tex
;
uniform float time;
uniform vec2 resolution;
uniform vec2 mouse;

void main(){

//    vec2 mousectr = mouse.xy / resolution.xy;  // remap mouse to a range of 0.0,1.0
    vec2 mousectr = vec2(0.5);  // set mouse at center

	vec2 st = gl_TexCoord[0].st; // get this texture coordinate


	vec2 uv = gl_FragCoord.st / resolution.xy ; // create a uv gradient
	vec2 ctr = vec2(mousectr); //set the center to mousepos
	vec2 ctrvec = ctr - uv; //get difference vector from fragment to center(or mouse)
	float ctrdist = length(ctrvec); //calculate distance from fragment to center
	ctrvec /= ctrdist; //get percentage based on distance

	uv += ctrvec * max(0.0, pow(ctrdist*0.9, 3.2 + sin(time)*0.9));
	vec3 color = vec3(0.0); //create a base color
	color = texture2DRect(tex, vec2(0.0, resolution.y) + vec2(resolution.x,-resolution.y)*uv).rgb;

    //mix colors using uv, just for fun
	color += mix(color, vec3(sin(time)*1. * uv.x,cos(time)*1. * uv.y, sin(time*1.5)*1.), 1.);

	gl_FragColor = vec4(color, 1.0);


}
