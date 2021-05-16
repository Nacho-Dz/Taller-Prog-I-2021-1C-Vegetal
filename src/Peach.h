#pragma once

#include <string>
#include "Entidad.h"
#include "Rendereable.h"
#include "ComponenteVistaEntidadEstatica.h"

class Peach : public Entidad, public Rendereable {
    public:

    Peach(int posX, int posY, int ancho, int alto);
    void mostrar(SDL_Renderer* renderer);
    std::string getRutaImagen();

    private:
    ComponenteVistaEntidadEstatica* compVista = new ComponenteVistaEntidadEstatica();
    std::string rutaImagen = "res/Peach.png";
};