/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::dynamicMotionSolverFvMesh

Description
    Dynamic FV mesh, where a motion solver is used to move the mesh.
    The user specifies motion using the boundary condition on the
    appropriate motion variable.

SourceFiles
    dynamicMotionSolverFvMesh.C

Author
    Hrvoje Jasak, Wikki Ltd.  All rights reserved

\*---------------------------------------------------------------------------*/

#ifndef rotationDeformationFvMesh_H
#define rotationDeformationFvMesh_H

#include "dynamicFvMesh.H"
#include "cylindricalCS.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class motionSolver;

/*---------------------------------------------------------------------------*\
                   Class dynamicMotionSolverFvMesh Declaration
\*---------------------------------------------------------------------------*/

class rotationDeformationFvMesh
:
    public dynamicFvMesh
{
    // Private data

        autoPtr<motionSolver> motionPtr_;
		
		//- Motion dictionary
        dictionary dict_;

        //- Coordinate system
        cylindricalCS cs_;

        //- Markup field for points.
        mutable vectorField* movingPointsPtr_;

		double testVariable_ = 0;

    // Private Member Functions

        //- Disallow default bitwise copy construct
        rotationDeformationFvMesh(const rotationDeformationFvMesh&);

        //- Disallow default bitwise assignment
        void operator=(const rotationDeformationFvMesh&);

		//- Calculate moving Points
        void calcMovingPoints() const;

        //- Return moving points
        const vectorField& movingPoints() const;

public:

    //- Runtime type information
    TypeName("rotationDeformationFvMesh");


    // Constructors
	
	//- Construct from IOobject
       // explicit rotationDeformationFvMesh(const IOobject& io); // from turbo
    
    //- Construct from IOobject
        rotationDeformationFvMesh(const IOobject& io);


    // Destructor

        virtual ~rotationDeformationFvMesh();


    // Member Functions

		//- Return coordinate system
        const cylindricalCS& cs() const
        {
            return cs_;
        }
		
        //- Update the mesh for both mesh motion and topology change
        virtual bool update();
		
		
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
