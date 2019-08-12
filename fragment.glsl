uniform mediump vec4 color;
uniform mediump vec2 size;
varying mediump vec4 fragmentColor;

void main(void)
{
   gl_FragColor = fragmentColor;
//   gl_FragColor = color;
//   gl_FragColor.x = 1.0;
//   gl_FragColor.y = gl_FragCoord.x / size.x;
//   gl_FragColor.z = 0.0;
//   gl_FragColor.w = 1.0;
}
