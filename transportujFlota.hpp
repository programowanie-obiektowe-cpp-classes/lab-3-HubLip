#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
    {
        return 0; //Jezeli towar jest 0 to nie tworzymy zadnego statku
    }

    Stocznia stocznia{};
    unsigned int iloscTowaru = 0;
    unsigned int sumarycznyTowar = 0; 
    unsigned int licznikZaglowcow = 0;

    while (sumarycznyTowar <= towar )
    {
        Statek* s1 = stocznia();

        iloscTowaru = s1 -> transportuj();
        sumarycznyTowar += iloscTowaru;

        if (dynamic_cast<Zaglowiec*>(s1))
        {
            ++licznikZaglowcow;
        }
        delete s1;
    }
    return licznikZaglowcow;
}