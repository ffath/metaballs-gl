#include "metaballs.h"

#include <QOpenGLFunctions>
#include <QDebug>


Metaballs::Metaballs(QWidget *parent) : QOpenGLWidget(parent), m_shaderProgram(nullptr)
{
    qDebug() << __func__;
}

Metaballs::~Metaballs()
{
    qDebug() << __func__;
}

void Metaballs::initializeGL()
{
    qDebug() << __func__;

    m_shaderProgram = new QOpenGLShaderProgram();
    m_shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex.glsl");
    m_shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment.glsl");
    m_shaderProgram->link();
    m_shaderProgram->bind();

}

void Metaballs::paintGL()
{
    static QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    QSize s = size();
    GLfloat w = static_cast<GLfloat>(s.width());
    GLfloat h = static_cast<GLfloat>(s.height());
//    GLfloat const triangleVertices[] = {
//        0.0f, h   , 0.0f,
//        0.0f, 0.0f, 0.0f,
//        w   , h   , 0.0f,
//        w   , 0.0f, 0.0f
//    };
    GLfloat const triangleVertices[] = {
        -w / 2.0f,  h / 2.0f, 0.0f,
        -w / 2.0f, -h / 2.0f, 0.0f,
         w / 2.0f,  h / 2.0f, 0.0f,
         w / 2.0f, -h / 2.0f, 0.0f
    };
    GLfloat const verticesColors[] = {
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    };
    QColor color(255, 0, 0, 255);
    QMatrix4x4 pmvMatrix;

    qDebug() << __func__ ;

    pmvMatrix.ortho(rect());
    pmvMatrix.translate(w / 2.0f, h / 2.0f);

    int vertexLocation = m_shaderProgram->attributeLocation("vertex");
    int vertexColorLocation = m_shaderProgram->attributeLocation("vertexColor");
    int matrixLocation = m_shaderProgram->uniformLocation("matrix");
    int colorLocation = m_shaderProgram->uniformLocation("color");
    int sizeLocation = m_shaderProgram->uniformLocation("size");

    m_shaderProgram->enableAttributeArray(vertexLocation);
    m_shaderProgram->setAttributeArray(vertexLocation, triangleVertices, 3);
    m_shaderProgram->enableAttributeArray(vertexColorLocation);
    m_shaderProgram->setAttributeArray(vertexColorLocation, verticesColors, 4);
    m_shaderProgram->setUniformValue(matrixLocation, pmvMatrix);
    m_shaderProgram->setUniformValue(colorLocation, color);
    m_shaderProgram->setUniformValue(sizeLocation, s);

    f->glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    m_shaderProgram->disableAttributeArray(vertexLocation);
    m_shaderProgram->disableAttributeArray(vertexColorLocation);
}
