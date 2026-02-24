//============================================================================================
// AstroLib v1.0 - Made by S.D. Samaraweera
// Age: 13 | Location: Sri Lanka.
// A library for astronomical physics and planetary data.
//made this because python as astropy so why not AstroLib.h for c++?
//next version i will make more math and add some more stars and black holes
//upcoming date 2027 january or december!
//=============================================================================================
//some formulas demand SI units so watch out!
#pragma once        //safety first
#include <cmath>

namespace Astro {
    // 1. Constants please do not change!
    constexpr double G = 6.67430e-11; 
    constexpr double PI = 3.1415926535;
    constexpr double WIENS_CONSTANT = 0.00289777;
    constexpr double STEFAN_BOLTZMANN = 5.670367e-8;
    constexpr double EARTH_R = 6.37e6;
    constexpr double LIGHT_SPEED_MS = 299792458.0; // Meters per second
    constexpr double AU_METERS = 1.496e11;         // Distance from Earth to Sun

    // 2. Formulas
    inline double GetStarBrightness(double temparature_K,double star_core_radius){
    	return 4*PI*std::pow(star_core_radius,2)*STEFAN_BOLTZMANN*std::pow(temparature_K,4);
	}
	
	inline double GetStarIntensity(double distance_M ,double brightness){
		return brightness/(4*PI*std::pow(distance_M,2));
	}
	
	inline double GetStarWavelenght(double Temparature){
		return WIENS_CONSTANT/Temparature;
	}
	
	inline double GetBlackHolesEventHorizon(double mass){
		return 2*G*mass/std::pow(LIGHT_SPEED_MS,2);
	}
	
	inline double GetStarTemparature(double wavelenght){
		return WIENS_CONSTANT/wavelenght;
	}
	
	inline double GetStarRealeasingEnergy(double mass){
		return mass*std::pow(LIGHT_SPEED_MS,2);
	}
    
	inline double GetSemiMajorAxis(double time) {
        return std::cbrt(std::pow(time, 2));
    }

    inline double GetOrbitalPeriod(double semiMajorAxis) {
        return std::sqrt(std::pow(semiMajorAxis, 3));
    }

    inline double GetPerihelion(double a, double e) {
        return a * (1.0 - e);
    }

    inline double GetAphelion(double a, double e) {
        return a*(1.0 + e);
    }

    inline double GetOrbitArea(double semiMinor, double semiMajor) {
        return PI * semiMajor * semiMinor;
    }

    inline double GetEscapeVelocity(double radius, double mass) {
        return std::sqrt(2.0 * G * mass / radius);
    }
    // do you think inserting 0 radius influsence my code? think agin!
    inline double GetSafeGravity(double mass, double radius) {
        if (radius <= 0) return 0.0;
        return (G * mass) / (radius * radius);
    }
    inline double GetSemiMajorAxisByPerihelion(double perihelion , double aphelion){
    	return (perihelion+aphelion)/2;
	}
	inline double GetSemiMinorAxis(double semimajoraxis , double e){
		return semimajoraxis*std::sqrt(1-std::pow(e,2));
	}
	inline double GetDistanceFromCenterToAnother(double e,double semimajoraxis){
		return e*semimajoraxis;
	}
	inline double DetermineTypeOfOrbit(double e){
		if(e>1) return 10;
		if(e==1) return 20;
		if(e==0) return 30;
		else return 40;
	}
	inline double FindStarsDistance(double arcsecs){
		return 1/arcsecs;
	}
	inline double FindStarsAll(double parsec){
		return 1/parsec;
	}
	inline double LightYearToMeters(double lightyear){
		return lightyear*9.46e15;
	}
	inline double LightYearToParsecs(double lightyears){
		return lightyears*0.306;
	}

    // 3. Planet Data Bank (Units: kg, m, s, degrees)
    //very helpful if you want a tutoring simulator or some thing
    //if some one needs colours in hex they are provided in coments
    
    //========================MEARCURY====================================
	namespace Mercury {
    	//surface color darkgreay because of basaltic rock&dust
    	//colour hex=#A5A5A5
        const double MASS_KG = 3.3011e23;         
        const double RADIUS_M = 2.4397e6;        
        const double GRAVITY_MS2 = 3.7;            
        const double REVOLVE_S = 7.600e6; 
        const double ESCAPE_MS = 4.25e3; 
        const double TILT_D = 0.034;             
    }
    
    //===================VENUS======================================
    namespace Venus {
    	//surface color pale yellow because of sorounded in thick clouds containing sulfuric acid
    	//color hex=#E3BB76
        const double MASS_KG = 4.8675e24;
        const double RADIUS_M = 6.0518e6;
        const double GRAVITY_MS2 = 8.87;
        const double REVOLVE_S = 1.941e7;
        const double ESCAPE_MS = 1.036e4;
        const double ROTATION_S = 2.0997e7; 
        const double TILT_D = 177.3;
    }
    
    //=====================EARTH=============================
    namespace Earth {
    	//color vivid blue because our atmosphere emites blue light + water
        //colour hex=#2E5FAC
		const double MASS_KG = 5.9722e24;
        const double RADIUS_M = 6.371e6;
        const double GRAVITY_MS2 = 9.80665;
        const double REVOLVE_S = 3.1557e7;
        const double ESCAPE_MS = 1.1186e4;
        const double ROTATION_S = 86400.0;
        const double TILT_D = 23.44;
        
        //----------------Our MOON-------------
        namespace Moon {
            const double MASS_KG = 7.342e22;
            const double RADIUS_M = 1.737e6;
            const double GRAVITY_MS2 = 1.62;
            const double DISTANCE_FROM_EARTH_M = 3.844e8; // Important for tutoring!
        }
    }
    
    //===================MARS=======================================
    namespace Mars {
    	//color rustly orange because surface is covered in ironoxide(rust)
    	//colour hex=E27B58
        const double MASS_KG = 6.417e23;
        const double RADIUS_M = 3.395e6; // this is Meters
        const double GRAVITY_MS2 = 3.75;
        const double REVOLVE_S = 5.9355e7;
        const double ESCAPE_MS = 5.027e3;
        const double ROTATION_S = 8.8642e4;
        const double TILT_D = 25.19;
        
        //-------------------MOONS-------------------------
        namespace Phobos { // The larger, closer moon
            const double MASS_KG = 1.0659e16;
            const double RADIUS_M = 1.126e4;    // Only 11km! (Very small)
            const double GRAVITY_MS2 = 0.0057;  // You could jump off this moon!
        }
        namespace Deimos { // The smaller, outer moon
            const double MASS_KG = 1.4762e15;
            const double RADIUS_M = 6.2e3;      // Only 6km!
            const double GRAVITY_MS2 = 0.003;//you dont even have to jump a light touch will get you flying!
        }
    }
    
    //-------------------JUPITER------------------------------
    namespace Jupiter {
    	//Tan & Orange because differet layer of ammonia&ammonium hydrosulfate ,water ,ice
        //colour hex=#D39C7E
		const double MASS_KG = 1.898e27;
        const double RADIUS_M = 7.1492e7;
        const double GRAVITY_MS2 = 24.79;
        const double REVOLVE_S = 3.743e8;
        const double ESCAPE_MS = 5.95e4;
        const double TILT_D = 3.13;
        
        //=============== MOONS OF JUPITER==============================
        namespace Ganymede { // The largest moon in the solar system!
            const double MASS_KG = 1.4819e23;
            const double RADIUS_M = 2.634e6;
            const double GRAVITY_MS2 = 1.428;
        }
        namespace Europa { // Might have an ocean underneath!
            const double MASS_KG = 4.8e22;
            const double RADIUS_M = 1.560e6;
            const double GRAVITY_MS2 = 1.314;
        }
    }
    
    //------------SATURN---------------------------------
    namespace Saturn {
    	//pale gold same like jupiter
    	//colour hex=#C5AB6E
        const double MASS_KG = 5.683e26;
        const double RADIUS_M = 5.8232e7;
        const double GRAVITY_MS2 = 10.44;
        const double REVOLVE_S = 9.295e8;
        const double ESCAPE_MS = 3.55e4;
        const double TILT_D = 26.73;
        
        //---------------MOONS-------------------------------------
        namespace Titan { // Has a thick atmosphere like Earth
            const double MASS_KG = 1.345e23;
            const double RADIUS_M = 2.574e6;
            const double GRAVITY_MS2 = 1.352;
        }
    }
    
    //==================Uranus==============================
    namespace Uranus {
    	//pale cyan because Methane upper atmosphere abbsorbing from sun
        //colour hex=#BBE1E4
		const double MASS_KG = 8.681e25;
        const double RADIUS_M = 2.5362e7;
        const double GRAVITY_MS2 = 8.69;
        const double REVOLVE_S = 2.651e9;
        const double ESCAPE_MS = 2.13e4;
        const double TILT_D = 97.77;
    }
    
    //=====================neptune=======================
    namespace Neptune {
    	//Deep Azure Blue because methene like urenus but with more darker
    	//hex=#6081FF
        const double MASS_KG = 1.024e26;
        const double RADIUS_M = 2.4622e7;
        const double GRAVITY_MS2 = 11.15;
        const double REVOLVE_S = 5.2e9;
        const double ESCAPE_MS = 2.35e4;
        const double TILT_D = 28.32;
        
        //-----------------MOON----------------------
        namespace Triton { // Orbits the "wrong" way!
            const double MASS_KG = 2.14e22;
            const double RADIUS_M = 1.353e6;
            const double GRAVITY_MS2 = 0.779;
        }
    }
    
    
    //planets end here! next dwarf planets&sun
    // ==================OUR STAR SUN =====================
    namespace Sun {
        const double MASS_KG = 1.989e30;      // 99.8% of the Solar System's mass!
        const double RADIUS_M = 6.957e8;
        const double GRAVITY_MS2 = 274.0;     // 28 times stronger than Earth
        const double SURFACE_TEMP_K = 5778.0; // Kelvin
        const double ROTATION_S = 2.16e6;     // About 25-35 days
    }

    // /////////////DWARF PLANETS //////////////////////
    
    //CERES
    namespace Ceres {
        const double MASS_KG = 9.39e21;
        const double RADIUS_M = 4.73e5;       // 473 km
        const double GRAVITY_MS2 = 0.27;      // Very low gravity!
        const double REVOLVE_S = 1.45e8;      // 4.6 Years
        const double TILT_D=4;
        const double ROTATION_S=9.27e4;
    }
    
    //PLUTO
    namespace Pluto {
        const double MASS_KG = 1.303e22;
        const double RADIUS_M = 1.188e6;
        const double GRAVITY_MS2 = 0.62;
        const double REVOLVE_S = 7.82e9;     // 248 Years!
        const double TILT_D = 122.5;  // It spins on its side too!
        const double ROTATION_S=5.864e4;	
	}
    
    //ERIS
    namespace Eris {
        const double MASS_KG = 1.66e22;      // Heavier than Pluto!
        const double RADIUS_M = 1.163e6;
        const double GRAVITY_MS2 = 0.82;
        const double REVOLVE_S = 1.76e10;    // 558 Years
        const double TILT_D=44;
        const double ROTATION_S =5.49e4;
	}
    
    //HAUMEA
    namespace Haumea {
        const double MASS_KG = 4.006e21;
        const double RADIUS_M = 7.98e5;       // Average radius (it's actually oval!)
        const double GRAVITY_MS2 = 0.401;
        const double REVOLVE_S = 9.07e9;      // 284 Earth Years
        const double ROTATION_S = 1.41e4;    // Only 3.9 hours! (The fastest spinner)
        const double TILT_D = 28;
	}
    
    //MAKEMAKE
    namespace Makemake {
        const double MASS_KG = 3.1e21;
        const double RADIUS_M = 7.15e5;       
        const double GRAVITY_MS2 = 0.5;
        const double REVOLVE_S = 9.63e9;      // 305 Earth Years
        const double ROTATION_S = 8.1e4;    // About 22.5 hours
    	const double TILT_D = 29;
	}

    // Mercury and Venus have 0 moons!.
    //AsroLib ends here!

}   //see you in V2.0
