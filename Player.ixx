/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Player;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.InvalidArgumentException;
import TrilogyOnline.SDK.Vector;
import TrilogyOnline.SDK.Physical;

export namespace TrilogyOnline
{
	namespace API
	{
		class CVehicle;
		class CObject;

		class CPlayer : public CPhysical
		{
		public:
			static constexpr auto Maximum = 10000u;

			enum class EFacing : UInt8
			{
				Forward,
				Left,
				Back,
				Right
			};

			enum class EWeapon : UInt8
			{
				Unarmed,
				BrassKnuckles,
				GolfClub,
				NightStick,
				Knife,
				BaseballBat,
				Shovel,
				PoolCue,
				Katana,
				Chainsaw,
				PurpleDildo,
				Dildo,
				Vibrator,
				SilverVibrator,
				Flowers,
				Cane,
				Grenade,
				TearGas,
				MolotovCocktail,
				Pistol = 22,
				PistolSilenced,
				DesertEagle,
				Shotgun,
				SawnoffShotgun,
				CombatShotgun,
				MicroUzi,
				MP5,
				AK47,
				M4,
				TEC9,
				CountryRifle,
				SniperRifle,
				RPG,
				HSRocket,
				Flamethrower,
				Minigun,
				SatchelCharge,
				Detonator,
				SprayCan,
				FireExtinguisher,
				Camera,
				NightVisionGoggles,
				ThermalGoggles,
				Parachute
			};

			enum class EWeaponSlot : UInt8
			{
				Hand,
				Melee,
				Handgun,
				Shotgun,
				MachinePistol,
				AssaultRifle,
				Rifle,
				Heavy,
				Thrown,
				Handheld,
				Gift,
				Apparel,
				Detonator
			};

			enum class EFightStyle : UInt8
			{
				Default = 4,
				Boxeo,
				KungFu,
				KickBoxing,
				Bat,
				Knife,
				GolfClub,
				Katana,
				Chainsaw,
				Dildo,
				NotCombos,
				YesCombos,
				Elbows
			};

			enum class ESeat : UInt8
			{
				Front,
				RearLeft,
				RearRight,
				Additional1,
				Additional2,
				Additional3,
				Additional4,
				Additional5,
				Invalid
			};

			enum class EPlacement : UInt8
			{
				None,
				OnFoot,
				InVehicleAsDriver,
				InVehicleAsPassenger
			};

			enum class EHand : UInt8
			{
				Right = 1,
				Left,
				Both
			};

			class CState
			{
			public:
				virtual void OnStreamIn(CPlayer& player, CPlayer& forPlayer) = 0;

				virtual void OnStreamOut(CPlayer& player, CPlayer& forPlayer) = 0;

				virtual void OnDeath(CPlayer& player) = 0;

				virtual void OnDeath(CPlayer& player, CPlayer& byPlayer) = 0;

				virtual void OnDeath(CPlayer& player, CVehicle& byVehicle) = 0;

				virtual void OnGiveDamage(CPlayer& player, CPlayer& damagedPlayer) = 0;

				virtual void OnUpdated(CPlayer& player) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnSyncingUserDataUpdated(CPlayer& player, const UInt64 oldValue, const UInt64 newValue) = 0;
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnMessageReceived(CPlayer& player, const Byte* const data, const NativeUInt size) = 0;
#endif
			};

			[[nodiscard]]
			static EWeaponSlot GetWeaponSlotByWeapon(const EWeapon& weapon)
			{
				switch (weapon)
				{
				case EWeapon::Unarmed:
					return EWeaponSlot::Hand;

				case EWeapon::BrassKnuckles:
					return EWeaponSlot::Hand;

				case EWeapon::GolfClub:
					return EWeaponSlot::Melee;

				case EWeapon::NightStick:
					return EWeaponSlot::Melee;

				case EWeapon::Knife:
					return EWeaponSlot::Melee;

				case EWeapon::BaseballBat:
					return EWeaponSlot::Melee;

				case EWeapon::Shovel:
					return EWeaponSlot::Melee;

				case EWeapon::PoolCue:
					return EWeaponSlot::Melee;

				case EWeapon::Katana:
					return EWeaponSlot::Melee;

				case EWeapon::Chainsaw:
					return EWeaponSlot::Melee;

				case EWeapon::PurpleDildo:
					return EWeaponSlot::Gift;

				case EWeapon::Dildo:
					return EWeaponSlot::Gift;

				case EWeapon::Vibrator:
					return EWeaponSlot::Gift;

				case EWeapon::SilverVibrator:
					return EWeaponSlot::Gift;

				case EWeapon::Flowers:
					return EWeaponSlot::Gift;

				case EWeapon::Cane:
					return EWeaponSlot::Gift;

				case EWeapon::Grenade:
					return EWeaponSlot::Thrown;

				case EWeapon::TearGas:
					return EWeaponSlot::Thrown;

				case EWeapon::MolotovCocktail:
					return EWeaponSlot::Thrown;

				case EWeapon::Pistol:
					return EWeaponSlot::Handgun;

				case EWeapon::PistolSilenced:
					return EWeaponSlot::Handgun;

				case EWeapon::DesertEagle:
					return EWeaponSlot::Handgun;

				case EWeapon::Shotgun:
					return EWeaponSlot::Shotgun;

				case EWeapon::SawnoffShotgun:
					return EWeaponSlot::Shotgun;

				case EWeapon::CombatShotgun:
					return EWeaponSlot::Shotgun;

				case EWeapon::MicroUzi:
					return EWeaponSlot::MachinePistol;

				case EWeapon::MP5:
					return EWeaponSlot::MachinePistol;

				case EWeapon::AK47:
					return EWeaponSlot::AssaultRifle;

				case EWeapon::M4:
					return EWeaponSlot::AssaultRifle;

				case EWeapon::TEC9:
					return EWeaponSlot::MachinePistol;

				case EWeapon::CountryRifle:
					return EWeaponSlot::Rifle;

				case EWeapon::SniperRifle:
					return EWeaponSlot::Rifle;

				case EWeapon::RPG:
					return EWeaponSlot::Heavy;

				case EWeapon::HSRocket:
					return EWeaponSlot::Heavy;

				case EWeapon::Flamethrower:
					return EWeaponSlot::Heavy;

				case EWeapon::Minigun:
					return EWeaponSlot::Heavy;

				case EWeapon::SatchelCharge:
					return EWeaponSlot::Thrown;

				case EWeapon::Detonator:
					return EWeaponSlot::Detonator;

				case EWeapon::SprayCan:
					return EWeaponSlot::Handheld;

				case EWeapon::FireExtinguisher:
					return EWeaponSlot::Handheld;

				case EWeapon::Camera:
					return EWeaponSlot::Handheld;

				case EWeapon::NightVisionGoggles:
					return EWeaponSlot::Apparel;

				case EWeapon::ThermalGoggles:
					return EWeaponSlot::Apparel;

				case EWeapon::Parachute:
					return EWeaponSlot::Apparel;
				}

				throw CInvalidArgumentException{ u"The passed weapon does not have a slot." };
			}

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void AttachToVehicle(CVehicle& vehicle, const CVector3DFloat& offset, const EFacing facing, const float angleLimit, const EWeapon weapon) = 0;

			virtual void AttachToObject(CObject& object, const CVector3DFloat& offset, const EFacing facing, const float angleLimit, const EWeapon weapon) = 0;

			virtual void GiveWeapon(const EWeapon weapon, const UInt32 ammo) = 0;

			virtual void RemoveWeapon(const EWeapon weapon) = 0;

			virtual void RemoveAllWeapons() = 0;

			virtual void SetActiveWeaponSlot(const EWeaponSlot value) = 0;

			[[nodiscard]]
			virtual EWeaponSlot GetActiveWeaponSlot() const = 0;

			virtual void SetAmmo(const EWeaponSlot weaponSlot, const UInt32 ammo) = 0;

			[[nodiscard]] virtual UInt32 GetAmmo(const EWeaponSlot weaponSlot) const = 0;

			virtual void FireGun(const EHand hand) = 0;
			
			virtual void SetMaxHealth(const float value) = 0;

			[[nodiscard]]
			virtual float GetMaxHealth() const = 0;

			virtual void SetHealth(const float value) = 0;

			[[nodiscard]]
			virtual float GetHealth() const = 0;

			virtual void SetArmor(const float value) = 0;

			[[nodiscard]]
			virtual float GetArmor() const = 0;

			virtual void SetFightStyle(const EFightStyle value) = 0;

			[[nodiscard]]
			virtual EFightStyle GetFightStyle() const = 0;	

			virtual void SetModelId(const UInt32 value) = 0;

			[[nodiscard]]
			virtual UInt32 GetModelId() const = 0;

			virtual void ToggleDucking(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsDucking() const = 0;

			virtual void EnterVehicleAsDriver(CVehicle& vehicle) = 0;

			virtual void EnterVehicleAsPassenger(CVehicle& vehicle) = 0;

			virtual void LeaveVehicle() = 0;

			virtual void PutIntoVehicleAsDriver(CVehicle& vehicle) = 0;

			virtual void PutIntoVehicleAsPassenger(CVehicle& vehicle, const ESeat seat) = 0;

			virtual void RemoveFromVehicleAndPutAt(const CVector3DFloat& position) = 0;

			[[nodiscard]]
			virtual CVehicle* GetVehicle() const = 0;

			[[nodiscard]]
			virtual ESeat GetSeat() const = 0;

			[[nodiscard]]
			virtual EPlacement GetPlacement() const = 0;

			virtual void Spawn(const UInt32 skinModelId, const CVector3DFloat& position, const float heading, const float health, const float armor) = 0;

#ifdef TRILOGY_ONLINE_SERVER
			virtual void SendUnreliableMessage(const Byte* const data, const NativeUInt size) = 0;

			virtual void SendReliableMessage(const Byte* const data, const NativeUInt size) = 0;
#endif
		};
	}
}