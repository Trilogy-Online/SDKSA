/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Physical;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Vector;
import TrilogyOnline.SDK.Entity;

export namespace TrilogyOnline
{
	namespace API
	{
		class CPhysical : public CEntity
		{
		public:
			virtual void SetVelocity(const CVector3DFloat& value) = 0;

			[[nodiscard]]
			virtual CVector3DFloat GetVelocity() const = 0;

			virtual void SetRotationalVelocity(const CVector3DFloat& value) = 0;

			[[nodiscard]]
			virtual CVector3DFloat GetRotationalVelocity() const = 0;

			virtual void SetMass(const float value) = 0;

			[[nodiscard]]
			virtual float GetMass() const = 0;

			virtual void SetRotationalMass(const float value) = 0;

			[[nodiscard]]
			virtual float GetRotationalMass() const = 0;

			virtual void ToggleControllability(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsControllable() const = 0;
		};
	}
}