/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Object;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Vector;
import TrilogyOnline.SDK.Physical;

export namespace TrilogyOnline
{
	namespace API
	{
		class CVehicle;
		class CPlayer;

		class CObject : public CPhysical
		{
		public:
			static constexpr auto Maximum = 100000u;

			class CState
			{
			public:
				virtual void OnStreamIn(CObject& object, CPlayer& forPlayer) = 0;

				virtual void OnStreamOut(CObject& object, CPlayer& forPlayer) = 0;

				virtual void OnMoved(CObject& object) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnSyncingUserDataUpdated(CObject& object, const UInt64 oldValue, const UInt64 newValue) = 0;
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void AttachToVehicle(CVehicle& vehicle, const CVector3DFloat& offset, const CVector3DFloat& rotation) = 0;

			virtual void AttachToPlayer(CPlayer& player, const CVector3DFloat& offset, const CVector3DFloat& rotation) = 0;

			virtual void AttachToObject(CObject& object, const CVector3DFloat& offset, const CVector3DFloat& rotation) = 0;

			virtual void SetHealth(const float value) = 0;

			[[nodiscard]]
			virtual float GetHealth() const = 0;

			virtual void SetDoorStartAngle(const float value) = 0;

			[[nodiscard]]
			virtual float GetDoorStartAngle() const = 0;

			virtual void SetScale(const float value) = 0;

			[[nodiscard]]
			virtual float GetScale() const = 0;

			virtual void SetModelId(const UInt32 value) = 0;

			[[nodiscard]]
			virtual UInt32 GetModelId() const = 0;

			virtual void Break(const float intensity) = 0;

			virtual void SetMaterial() = 0;
		};
	}
}