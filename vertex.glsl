attribute highp vec4 vertex;
attribute highp vec4 vertexColor;
uniform highp mat4 matrix;
varying mediump vec4 fragmentColor;

void main(void)
{
   gl_Position = matrix * vertex;
   fragmentColor = vertexColor;
//   fragmentColor = gl_Position;
}
