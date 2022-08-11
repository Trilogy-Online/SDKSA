/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Vehicle;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Vector;
import TrilogyOnline.SDK.Physical;

export namespace TrilogyOnline
{
	namespace API
	{
		class CPlayer;
		class CObject;

		class CVehicle : public CPhysical
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class ETire : UInt8
			{
				FrontLeft,
				RearLeft,
				FrontRight,
				RearRight
			};

			enum class EDoor : UInt8
			{
				Bonnet,
				Boot,
				FrontLeft,
				FrontRight,
				RearLeft,
				RearRight
			};

			enum class EDoorState : UInt8
			{
				Normal,
				Damaged,
				Popped
			};

			enum class EPanel : UInt8
			{
				WingFrontLeft,
				WingFrontRight,
				WingRearLeft,
				WingRearRight,
				Windscreen,
				BumperFront,
				BumperRear
			};

			enum class EPanelState : UInt8
			{
				Normal,
				Damaged,
				Popped
			};

			enum class ELightsState : UInt8
			{
				NoOverride,
				ForceOff,
				ForceOn
			};

			class CPainting
			{
			public:
				UInt8 PrimaryColor{ };
				UInt8 SecondaryColor{ };
				UInt8 TertiaryColor{ };
				UInt8 QuaternaryColor{ };

				constexpr CPainting() noexcept = default;

				constexpr CPainting(const UInt8 primaryColor, const UInt8 secondaryColor, const UInt8 tertiaryColor, const UInt8 quaternaryColor) noexcept :
					PrimaryColor{ primaryColor }, SecondaryColor{ secondaryColor }, TertiaryColor{ tertiaryColor }, QuaternaryColor{ quaternaryColor } { }
			};

			class CHydraulicForces
			{
			public:
				float First{ };
				float Second{ };
				float Third{ };
				float Fourth{ };

				constexpr CHydraulicForces() noexcept = default;

				constexpr CHydraulicForces(const float first, const float second, const float third, const float fourth) noexcept :
					First{ first }, Second{ second }, Third{ third }, Fourth{ fourth } { }
			};

			class CLandingGearStatus
			{
			public:
				float CurrentPosition{ };
				float TargetPosition{ };

				constexpr CLandingGearStatus() noexcept = default;

				constexpr CLandingGearStatus(const float currentPosition, const float targetPosition) noexcept :
					CurrentPosition{ currentPosition }, TargetPosition{ targetPosition } { }
			};

			class CState
			{
			private:
				using Self = CState;

			public:
				virtual void OnStreamIn(CVehicle& vehicle, CPlayer& forPlayer) = 0;

				virtual void OnStreamOut(CVehicle& vehicle, CPlayer& forPlayer) = 0;

				virtual void OnDeath(CVehicle& vehicle) = 0;

				virtual void OnDeath(CVehicle& vehicle, CPlayer& byPlayer) = 0;

				virtual void OnDeath(CVehicle& vehicle, CVehicle& byVehicle) = 0;

				virtual void OnPlayerEnters(CVehicle& vehicle, CPlayer& player) = 0;

				virtual void OnPlayerEntered(CVehicle& vehicle, CPlayer& player) = 0;

				virtual void OnPlayerLeaves(CVehicle& vehicle, CPlayer& player) = 0;

				virtual void OnPlayerLeft(CVehicle& vehicle, CPlayer& player) = 0;

				virtual void OnUpdated(CVehicle& vehicle, CPlayer& byPlayer) = 0;

				virtual void OnUnoccupiedUpdated(CVehicle& vehicle, CPlayer& byPlayer) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnSyncingUserDataUpdated(CVehicle& vehicle, const UInt64 oldValue, const UInt64 newValue) = 0;
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void AddMod(const UInt32 modelId) = 0;

			virtual void RemoveMod(const UInt32 modelId) = 0;

			virtual void AttachToVehicle(CVehicle& vehicle, const CVector3DFloat& offset, const CVector3DFloat& rotation) = 0;

			virtual void AttachToObject(CObject& object, const CVector3DFloat& offset, const CVector3DFloat& rotation) = 0;

			virtual void SetPainting(const CPainting& value) = 0;

			[[nodiscard]]
			virtual CPainting GetPainting() const = 0;

			virtual void SetPaintjob(const UInt8 value) = 0;

			[[nodiscard]]
			virtual UInt8 GetPaintjob() const = 0;

			virtual void SetHydraulicForces(const CHydraulicForces& value) = 0;

			[[nodiscard]]
			virtual CHydraulicForces GetHydraulicForces() const = 0;

			virtual void ResetHydraulics() = 0;

			virtual void SetMovablePartAngle(const float value) = 0;

			[[nodiscard]]
			virtual float GetMovablePartAngle() const = 0;

			virtual void ToggleTireInvulnerability(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsTireInvulnerable() const = 0;

			virtual void FixTire(const ETire tire) = 0;

			virtual void DamageTire(const ETire tire, const bool hasPhysicalEffect) = 0;

			[[nodiscard]]
			virtual bool IsTireDamaged(const ETire tire) const = 0;

			virtual void SetDoorOpenRatio(const EDoor door, const float openRatio, const bool hasSound) = 0;

			[[nodiscard]]
			virtual float GetDoorOpenRatio(const EDoor door) const = 0;

			virtual void FixDoor(const EDoor door) = 0;

			virtual void DamageDoor(const EDoor door) = 0;

			virtual void PopDoor(const EDoor door, const bool isVisible) = 0;

			[[nodiscard]]
			virtual EDoorState GetDoorState(const EDoor door) const = 0;

			virtual void FixPanel(const EPanel panel) = 0;

			virtual void DamagePanel(const EPanel panel) = 0;

			virtual void PopPanel(const EPanel panel, const bool isVisible) = 0;

			[[nodiscard]]
			virtual EPanelState GetPanelState(const EPanel panel) const = 0;

			virtual void SetLightsState(const ELightsState value) = 0;

			[[nodiscard]]
			virtual ELightsState GetLightsState() const = 0;

			virtual void ToggleTaxiLights(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsTaxiLightsEnabled() const = 0;

			virtual void ToggleSiren(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsSirenEnabled() const = 0;

			virtual void ToggleEngineBroken(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsEngineBroken() const = 0;

			virtual void ToggleEngine(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsEngineRunning() const = 0;

			virtual void SetHealth(const float value) = 0;

			[[nodiscard]]
			virtual float GetHealth() const = 0;

			virtual void ToggleInvulnerability(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsInvulnerable() const = 0;

			virtual void ToggleWatertight(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsWatertightEnabled() const = 0;

			virtual void SetDirtLevel(const float value) = 0;

			[[nodiscard]]
			virtual float GetDirtLevel() const = 0;

			virtual void Fix() = 0;

			virtual void Explode() = 0;

			virtual void SetLandingGearStatus(const CLandingGearStatus& value) = 0;

			[[nodiscard]]
			virtual CLandingGearStatus GetLandingGearStatus() const = 0;
		};
	}
}