/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Entities;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Vector;
import TrilogyOnline.SDK.InvalidArgumentException;
import TrilogyOnline.SDK.Placeable;
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
				Parachute,
				Armor,
				Vehicle = 49, // use only as a cause of death
				HeliBlades, // use only as a cause of death
				Explosion, // use only as a cause of death
				Drown = 53, // use only as a cause of death
				Collision, // use only as a cause of death
				Invalid = 255
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
				virtual ~CState() noexcept = default;

				virtual void OnDeath(CPlayer& player, const EWeapon weapon) { }

				virtual void OnDeath(CPlayer& player, CPlayer& byPlayer, const EWeapon weapon) { }

				virtual void OnDeath(CPlayer& player, CVehicle& byVehicle, const EWeapon weapon) { }

				virtual void OnGiveDamage(CPlayer& player, CPlayer& damagedPlayer) { }

				virtual void OnTakeDamage(CPlayer& player, CPlayer& damagingPlayer) { }	

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnStreamIn(CPlayer& player) { }

				virtual void OnStreamOut(CPlayer& player) { }

				virtual void OnSyncingUserDataUpdated(CPlayer& player, const UInt64 oldValue, const UInt64 newValue) { }
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnStreamIn(CPlayer& player, CPlayer& forPlayer) { }

				virtual void OnStreamOut(CPlayer& player, CPlayer& forPlayer) { }

				virtual void OnPlaceUpdated(CPlayer& player, const CVector3DFloat& newPosition, const CVector3DFloat& newVelocity, const CVector3DFloat& newRotation, const CVector3DFloat& newRotationalVelocity, bool& isOk) { }

				virtual void OnFireGun(CPlayer& player, const EWeaponSlot activeWeaponSlot, const EHand hand, bool& isOk) { }

				virtual void OnHealthUpdated(CPlayer& player, const float newHealth, bool& isOk) { }

				virtual void OnArmorUpdated(CPlayer& player, const float newArmor, bool& isOk) { }

				virtual void OnActiveWeaponSlotUpdated(CPlayer& player, const EWeaponSlot newWeaponSlot, bool& isOk) { }

				virtual void OnMessageReceived(CPlayer& player, const Byte* const data, const NativeUInt size) { }
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

			enum class ETireState : UInt8
			{
				Ok,
				Burst,
				Missing
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
				Ok,
				OkAndSwinging,
				Smashed,
				SmashedAndSwinging,
				Missing
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
				Ok,
				Smashed,
				Swinging,
				Missing
			};

			enum class ELight : UInt8
			{
				FrontLeft,
				FrontRight,
				RearRight,
				RearLeft
			};

			enum class ELightState : UInt8
			{
				Ok,
				Broken
			};

			enum class ELightsState : UInt8
			{
				NoOverride,
				ForceOff,
				ForceOn
			};

			enum class EDoorLockState : UInt8
			{
				NotUsed,
				Unlocked,
				Locked,
				LockoutPlayerOnly,
				LockedPlayerInside,
				LockedInitially,
				ForceShutDoors,
				SkipShutDoors
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

			class CLandingGearState
			{
			public:
				float CurrentPosition{ };
				float TargetPosition{ };

				constexpr CLandingGearState() noexcept = default;

				constexpr CLandingGearState(const float currentPosition, const float targetPosition) noexcept :
					CurrentPosition{ currentPosition }, TargetPosition{ targetPosition } { }
			};

			class CState
			{
			public:
				virtual ~CState() noexcept = default;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnStreamIn(CVehicle& vehicle) { }

				virtual void OnStreamOut(CVehicle& vehicle) { }

				virtual void OnSyncingUserDataUpdated(CVehicle& vehicle, const UInt64 oldValue, const UInt64 newValue) { }
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnStreamIn(CVehicle& vehicle, CPlayer& forPlayer) { }

				virtual void OnStreamOut(CVehicle& vehicle, CPlayer& forPlayer) { }

				virtual void OnPlayerEnters(CVehicle& vehicle, CPlayer& player, bool& isOk) { }

				virtual void OnPlayerEntered(CVehicle& vehicle, CPlayer& player, const bool isDriver, const CPlayer::ESeat seat, bool& isOk) { }

				virtual void OnPlayerLeaves(CVehicle& vehicle, CPlayer& player, bool& isOk) { }

				virtual void OnPlayerLeft(CVehicle& vehicle, CPlayer& player, bool& isOk) { }

				virtual void OnLandingGearStateUpdated(CVehicle& vehicle, CPlayer& byPlayer, const CLandingGearState& newLandingGearState, bool& isOk) { }

				virtual void OnMovablePartAngleUpdated(CVehicle& vehicle, CPlayer& byPlayer, const float newAngle, bool& isOk) { }

				virtual void OnPlaceUpdated(CVehicle& vehicle, CPlayer& byPlayer, const CVector3DFloat& newPosition, const CVector3DFloat& newVelocity, const CVector3DFloat& newRotation, const CVector3DFloat& newRotationalVelocity, bool& isOk) { }

				virtual void OnUnoccupiedPlaceUpdated(CVehicle& vehicle, CPlayer& byPlayer, const CVector3DFloat& newPosition, const CVector3DFloat& newVelocity, const CVector3DFloat& newRotation, const CVector3DFloat& newRotationalVelocity, bool& isOk) { }

				virtual void OnHealthUpdated(CVehicle& vehicle, CPlayer& byPlayer, const float newHealth, bool& isOk) { }

				virtual void OnTiresStateUpdated(CVehicle& vehicle, CPlayer& byPlayer, const ETireState newFrontLeft, const ETireState newRearLeft, const ETireState newFrontRight, const ETireState newRearRight, bool& isOk) { }

				virtual void OnDoorsStateUpdated(CVehicle& vehicle, CPlayer& byPlayer, const EDoorState newBonnet, const EDoorState newBoot, const EDoorState newFrontLeft, const EDoorState newFrontRight, const EDoorState newRearLeft, const EDoorState newRearRight, bool& isOk) { }

				virtual void OnLightsStateUpdated(CVehicle& vehicle, CPlayer& byPlayer, const ELightState newFrontLeft, const ELightState newFrontRight, const ELightState newRearRight, const ELightState newRearLeft, bool& isOk) { }

				virtual void OnPanelsStateUpdated(CVehicle& vehicle, CPlayer& byPlayer, const EPanelState newWingFrontLeft, const EPanelState newWingFrontRight, const EPanelState newWingRearLeft, const EPanelState newWingRearRight, const EPanelState newWindscreen, const EPanelState newBumperFront, const EPanelState newBumperRear, bool& isOk) { }

				virtual void OnExploded(CVehicle& vehicle, CPlayer& byPlayer, bool& isOk) { }

				virtual void OnEngineBroken(CVehicle& vehicle, CPlayer& byPlayer, bool& isOk) { }
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

			virtual void SetDoorOpenRatio(const EDoor door, const float openRatio, const bool hasSound) = 0;

			[[nodiscard]]
			virtual float GetDoorOpenRatio(const EDoor door) const = 0;

			virtual void SetTireState(const ETire tire, const ETireState tireState, const bool hasPhysicalEffectForBurstState = true) = 0;

			[[nodiscard]]
			virtual ETireState GetTireState(const ETire tire) const = 0;

			virtual void SetDoorState(const EDoor door, const EDoorState doorState, const bool spawnFlyingComponentForMissingState = false) = 0;

			[[nodiscard]]
			virtual EDoorState GetDoorState(const EDoor door) const = 0;

			virtual void SetPanelState(const EPanel panel, const EPanelState panelState, const bool spawnFlyingComponentForMissingState = false) = 0;

			[[nodiscard]]
			virtual EPanelState GetPanelState(const EPanel panel) const = 0;

			virtual void SetLightState(const ELight light, const ELightState lightState) = 0;

			[[nodiscard]]
			virtual ELightState GetLightState(const ELight light) const = 0;

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

			[[nodiscard]]
			virtual bool IsExploded() const = 0;

			virtual void SetLandingGearState(const CLandingGearState& value) = 0;

			[[nodiscard]]
			virtual CLandingGearState GetLandingGearState() const = 0;

			virtual void SetDoorLockState(const EDoorLockState value) = 0;

			[[nodiscard]]
			virtual EDoorLockState GetDoorLockState() const = 0;
		};

		class CBlip : public CPlaceable
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class ESprite : UInt8
			{
				None,
				White,
				Centre,
				MapHere,
				North,
				Airyard,
				AmmuGun,
				Barbers,
				BigSmoke,
				Boatyard,
				BurgerShot,
				Bulldozer,
				CatalinaPink,
				CesarViapando,
				Chicken,
				CJ,
				CRASH,
				Diner,
				EmmetGun,
				EnemyAttack,
				Fire,
				Girlfriend,
				Hostpital,
				LocoSyndicate,
				MaddDogg,
				MafiaCasino,
				MCStrap,
				ModGarage,
				OGLoc,
				Pizza,
				Police,
				PropertyGreen,
				PropertyRed,
				Race,
				Ryder,
				SaveGame,
				School,
				QuestionMark,
				Sweet,
				Tattoo,
				TheTruth,
				Waypoint,
				TorenoRanch,
				Triads,
				TriadsCasino,
				Tshirt,
				Woozie,
				Zero,
				Disco,
				Drink,
				Food,
				Truck,
				Cash,
				Flag,
				GYM,
				Impound,
				Light,
				Runway,
				GangBlue,
				GangPurple,
				GangYellow,
				GangN, // N?
				GangGreen,
				Spray
			};

			enum class EColor : UInt8
			{
				Red,
				Green,
				Blue,
				White,
				Yellow,
				RedCopy,
				BlueCopy,
				Threat,
				Destination
			};

			class CState
			{
			public:
				virtual ~CState() noexcept = default;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnStreamIn(CBlip& blip) { }

				virtual void OnStreamOut(CBlip& blip) { }

				virtual void OnSyncingUserDataUpdated(CBlip& blip, const UInt64 oldValue, const UInt64 newValue) { }
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnStreamIn(CBlip& blip, CPlayer& forPlayer) { }

				virtual void OnStreamOut(CBlip& blip, CPlayer& forPlayer) { }
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void SetSprite(const ESprite value) = 0;

			[[nodiscard]]
			virtual ESprite GetSprite() const = 0;

			virtual void SetColor(const EColor value) = 0;

			[[nodiscard]]
			virtual EColor GetColor() const = 0;

			virtual void ToggleShortRange(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsShortRange() const = 0;

			virtual void SetScale(const UInt16 value) = 0;

			[[nodiscard]]
			virtual UInt16 GetScale() const = 0;
		};

		class CCheckpoint : public CPlaceable
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class EType : UInt8
			{
				Normal,
				Finish,
				Nothing,
				AirNormal,
				AirFinish,
				AirRotatesAndStops,
				AirIncreasesAndDecreasesAndDisappears,
				AirSwingsDownAndUp1,
				AirSwingsDownAndUp2
			};

			class CState
			{
			public:
				virtual ~CState() noexcept = default;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnStreamIn(CCheckpoint& checkpoint) { }

				virtual void OnStreamOut(CCheckpoint& checkpoint) { }

				virtual void OnPlayerEntered(CCheckpoint& checkpoint) { }

				virtual void OnPlayerLeft(CCheckpoint& checkpoint) { }

				virtual void OnSyncingUserDataUpdated(CCheckpoint& checkpoint, const UInt64 oldValue, const UInt64 newValue) { }
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnStreamIn(CCheckpoint& checkpoint, CPlayer& forPlayer) { }

				virtual void OnStreamOut(CCheckpoint& checkpoint, CPlayer& forPlayer) { }

				virtual void OnPlayerEntered(CCheckpoint& checkpoint, CPlayer& player) { }

				virtual void OnPlayerLeft(CCheckpoint& checkpoint, CPlayer& player) { }
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void SetType(const EType value) = 0;

			[[nodiscard]]
			virtual EType GetType() const = 0;

			virtual void SetNextPosition(const CVector3DFloat& value) = 0;

			[[nodiscard]]
			virtual CVector3DFloat GetNextPosition() const = 0;

			virtual void SetRadius(const float value) = 0;

			[[nodiscard]]
			virtual float GetRadius() const = 0;

			virtual void SetColor(const UInt32 value) = 0;

			[[nodiscard]]
			virtual UInt32 GetColor() const = 0;

			virtual void SetPulsePeriod(const UInt16 value) = 0;

			[[nodiscard]]
			virtual UInt16 GetPulsePeriod() const = 0;

			virtual void SetPulseFraction(const float value) = 0;

			[[nodiscard]]
			virtual float GetPulseFraction() const = 0;

			virtual void SetRotateRate(const UInt16 value) = 0;

			[[nodiscard]]
			virtual UInt16 GetRotateRate() const = 0;
		};

		class CObject : public CPhysical
		{
		public:
			static constexpr auto Maximum = 100000u;

			class CState
			{
			public:
				virtual ~CState() noexcept = default;

				virtual void OnMoved(CObject& object) { }

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnStreamIn(CObject& object) { }

				virtual void OnStreamOut(CObject& object) { }

				virtual void OnSyncingUserDataUpdated(CObject& object, const UInt64 oldValue, const UInt64 newValue) { }
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnStreamIn(CObject& object, CPlayer& forPlayer) { }

				virtual void OnStreamOut(CObject& object, CPlayer& forPlayer) { }
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

		class CPickup : public CPlaceable
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class EType : UInt8
			{
				None,
				InShop,
				OnStreet,
				Once,
				OnceTimeout,
				OnceTimeoutSlow,
				Collectable,
				InShopOutOfStock,
				Money,
				MineInactive,
				MineArmed,
				NauticalMineInactive,
				NauticalMineArmed,
				FloatingPackage,
				FloatingPackageFloating,
				OnStreetSlow,
				AssetRevenue,
				PropertyLocked,
				PropertyForSale,
				MoneyDoesntdisappear,
				Snapshot,
				SecondPlayer,
				OnceForMission
			};

			class CState
			{
			public:
				virtual ~CState() noexcept = default;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnStreamIn(CPickup& pickup) { }

				virtual void OnStreamOut(CPickup& pickup) { }

				virtual void OnCollected(CPickup& pickup) { }

				virtual void OnSyncingUserDataUpdated(CPickup& pickup, const UInt64 oldValue, const UInt64 newValue) { }
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnStreamIn(CPickup& pickup, CPlayer& forPlayer) { }

				virtual void OnStreamOut(CPickup& pickup, CPlayer& forPlayer) { }

				virtual void OnCollected(CPickup& pickup, CPlayer& byPlayer) { }
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void SetType(const EType value) = 0;

			[[nodiscard]]
			virtual EType GetType() const = 0;

			virtual void SetModelId(const UInt32 value) = 0;

			[[nodiscard]]
			virtual UInt32 GetModelId() const = 0;
		};
	}
}