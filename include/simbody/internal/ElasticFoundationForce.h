#ifndef SimTK_SIMBODY_ELASTIC_FOUNDATION_FORCE_H_
#define SimTK_SIMBODY_ELASTIC_FOUNDATION_FORCE_H_

/* -------------------------------------------------------------------------- *
 *                      SimTK Core: SimTK Simbody(tm)                         *
 * -------------------------------------------------------------------------- *
 * This is part of the SimTK Core biosimulation toolkit originating from      *
 * Simbios, the NIH National Center for Physics-Based Simulation of           *
 * Biological Structures at Stanford, funded under the NIH Roadmap for        *
 * Medical Research, grant U54 GM072970. See https://simtk.org.               *
 *                                                                            *
 * Portions copyright (c) 2008 Stanford University and the Authors.           *
 * Authors: Peter Eastman                                                     *
 * Contributors:                                                              *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining a    *
 * copy of this software and associated documentation files (the "Software"), *
 * to deal in the Software without restriction, including without limitation  *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
 * and/or sell copies of the Software, and to permit persons to whom the      *
 * Software is furnished to do so, subject to the following conditions:       *
 *                                                                            *
 * The above copyright notice and this permission notice shall be included in *
 * all copies or substantial portions of the Software.                        *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 * THE AUTHORS, CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,    *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR      *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  *
 * USE OR OTHER DEALINGS IN THE SOFTWARE.                                     *
 * -------------------------------------------------------------------------- */


#include "SimTKcommon.h"

#include "simbody/internal/common.h"
#include "simbody/internal/Force.h"

namespace SimTK {

class GeneralContactSubsystem;
class ElasticFoundationForceImpl;

class SimTK_SIMBODY_EXPORT ElasticFoundationForce : public Force {
public:
    /**
     * Create an elastic foundation contact model.
     * 
     * @param contacts       the subsystem to which this contact model should be applied
     * @param contactSet     the index of the contact set to which this contact model will be applied
     * @param meshIndex      the index within the contact set of the triangle mesh this force applies to
     */
    ElasticFoundationForce(GeneralForceSubsystem& forces, GeneralContactSubsystem& contacts, ContactSetIndex contactSet, int meshIndex);
    Real getYoungsModulus() const;
    void setYoungsModulus(Real v);
    Real getPoissonsRatio() const;
    void setPoissonsRatio(Real v);
    Real getThickness() const;
    void setThickness(Real v);
    Real getTransitionVelocity() const;
    void setTransitionVelocity(Real v);
    SimTK_INSERT_DERIVED_HANDLE_DECLARATIONS(ElasticFoundationForce, ElasticFoundationForceImpl, Force);
};

} // namespace SimTK

#endif // SimTK_SIMBODY_ELASTIC_FOUNDATION_FORCE_H_
