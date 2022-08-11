/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <chrono>

export module TrilogyOnline.SDK.Game;

import TrilogyOnline.SDK.Fundamental;

import TrilogyOnline.SDK.Blip;
import TrilogyOnline.SDK.Checkpoint;
import TrilogyOnline.SDK.Object;
import TrilogyOnline.SDK.Pickup;
import TrilogyOnline.SDK.Vehicle;

import TrilogyOnline.SDK.Browser;
import TrilogyOnline.SDK.ScreenBrowser;
import TrilogyOnline.SDK.GameObjectBrowser;

export namespace TrilogyOnline
{
	namespace API
	{
		class CGame
		{
		public:
			class CState
			{
			public:
				virtual ~CState() noexcept = default;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnMessageReceived(CGame& game, const Byte* const data, const NativeUInt size) = 0;

				virtual void OnGameThreadTick(CGame& game) = 0;

				virtual void OnRendererThreadTick(CGame& game) = 0;

				virtual void OnConnected(CGame& game) = 0;

				virtual void OnDisconnected(CGame& game) = 0;

				virtual void OnRemoteBlipCreated(CGame& game, CBlip& blip) = 0;

				virtual void OnRemoteBlipDestroyed(CGame& game, CBlip& blip) = 0;

				virtual void OnRemoteCheckpointCreated(CGame& game, CCheckpoint& checkpoint) = 0;

				virtual void OnRemoteCheckpointDestroyed(CGame& game, CCheckpoint& checkpoint) = 0;

				virtual void OnRemoteObjectCreated(CGame& game, CObject& object) = 0;

				virtual void OnRemoteObjectDestroyed(CGame& game, CObject& object) = 0;

				virtual void OnRemotePickupCreated(CGame& game, CPickup& pickup) = 0;

				virtual void OnRemotePickupDestroyed(CGame& game, CPickup& pickup) = 0;

				virtual void OnRemotePlayerCreated(CGame& game, CPlayer& player) = 0;

				virtual void OnRemotePlayerDestroyed(CGame& game, CPlayer& player) = 0;

				virtual void OnRemoteVehicleCreated(CGame& game, CVehicle& vehicle) = 0;

				virtual void OnRemoteVehicleDestroyed(CGame& game, CVehicle& vehicle) = 0;
#endif

#ifdef TRILOGY_ONLINE_SERVER
				virtual void OnTick(CGame& game) = 0;

				virtual void OnPlayerConnected(CGame& game, CPlayer& player) = 0;

				virtual void OnPlayerDisconnected(CGame& game, CPlayer& player) = 0;
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			[[nodiscard]]
			virtual CBlip* CreateBlip(const CVector3DFloat& position, const CBlip::ESprite sprite, const CBlip::EColor color, const UInt16 scale, const bool shortRange) = 0;

			[[nodiscard]]
			virtual CCheckpoint* CreateCheckpoint(const CCheckpoint::EType type, const CVector3DFloat& position, const CVector3DFloat& nextPosition, const float radius, const UInt32 color, const UInt16 pulsePeriod = 1024, const float pulseFraction = 0.075f, const UInt16 rotateRate = 0) = 0;

			[[nodiscard]]
			virtual CObject* CreateObject(const UInt32 modelId, const CVector3DFloat& position, const CVector3DFloat& rotation) = 0;

			[[nodiscard]]
			virtual CPickup* CreatePickup(const UInt32 modelId, const CPickup::EType type, const CVector3DFloat& position) = 0;

			[[nodiscard]]
			virtual CVehicle* CreateVehicle(const UInt32 modelId, const CVector3DFloat& position, const CVector3DFloat& rotation, const CVehicle::CPainting& painting, const float health) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
			virtual void SendUnreliableMessage(const Byte* const data, const NativeUInt size) = 0;

			virtual void SendReliableMessage(const Byte* const data, const NativeUInt size) = 0;

			[[nodiscard]]
			virtual CScreenBrowser* CreateScreenBrowser(const std::u16string_view url) = 0;

			[[nodiscard]]
			virtual CScreenBrowser* CreateScreenBrowser(const CVector2DInt32& position, const CVector2DUInt32& size, const std::u16string_view url) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserBoolMultiArgument(const bool value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserInt8MultiArgument(const Int8 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserUInt8MultiArgument(const UInt8 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserInt16MultiArgument(const Int16 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserUInt16MultiArgument(const UInt16 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserInt32MultiArgument(const Int32 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserUInt32MultiArgument(const UInt32 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserInt64MultiArgument(const Int64 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserUInt64MultiArgument(const UInt64 value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserFloatMultiArgument(const float value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserDoubleMultiArgument(const double value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserLongDoubleMultiArgument(const long double value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserStringMultiArgument(const std::u16string& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserStringMultiArgument(std::u16string&& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserArrayViewMultiArgument(const std::vector<CBrowser::CMultiArgument*>& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserArrayViewMultiArgument(std::vector<CBrowser::CMultiArgument*>&& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserObjectViewMultiArgument(const std::map<std::u16string, CBrowser::CMultiArgument*>& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserObjectViewMultiArgument(std::map<std::u16string, CBrowser::CMultiArgument*>&& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserArrayMultiArgument(std::vector<std::unique_ptr<CBrowser::CMultiArgument>>&& value) = 0;

			[[nodiscard]]
			virtual CBrowser::CMultiArgument* CreateBrowserObjectMultiArgument(std::map<std::u16string, std::unique_ptr<CBrowser::CMultiArgument>>&& value) = 0;

			virtual void ToggleArea69SAMSite(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsArea69SAMSiteEnabled() const = 0;

			virtual void ToggleAircraftCarrierSAMSite(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsAircraftCarrierSAMSiteEnabled() const = 0;

			virtual void SetControllablePlayerMoney(const Int32 value) = 0;

			[[nodiscard]]
			virtual Int32 GetControllablePlayerMoney() const = 0;

			virtual void ToggleCursor(const bool value) = 0;

			virtual void SetCamera(const CVector3DFloat& position, const CVector3DFloat& lookAtPosition) = 0;

			virtual void SetMovingCamera(const CVector3DFloat& positionStart, const CVector3DFloat& positionEnd, const CVector3DFloat& lookAtPositionStart, const CVector3DFloat& lookAtPositionEnd, const float positionDuration, const float lookAtPositionDuration, const bool isPositionEase, const bool isLookAtPositionEase) = 0;

			virtual void SetCameraBehindControllablePlayer() = 0;

			virtual void SetWeather(const UInt16 weather) = 0;

			virtual void SetClock(const UInt8 hours, const UInt8 minutes) = 0;

			virtual void ToggleHUDDisplay(const bool value) = 0;

			virtual void ToggleAreaNameDisplay(const bool value) = 0;

			virtual void ToggleVehicleNameDisplay(const bool value) = 0;

			virtual void ToggleRadarDisplay(const bool value) = 0;

			[[nodiscard]]
			virtual CPlayer* GetControllablePlayer() const = 0;
			
			virtual void Quit() = 0;
			
			[[nodiscard]]
			virtual CVector2DFloat GetMousePositionDelta() const = 0;

			[[nodiscard]]
			virtual CVector2DUInt32 GetWindowSize() const = 0;

			[[nodiscard]]
			virtual bool CalcScreenCoords(const CVector3DFloat& position, CVector3DFloat& screenCoords, float& width, float& height) const = 0;

			virtual void RequestModel(const UInt32 modelId) = 0;

			virtual void LoadAllRequestedModels() = 0;
#endif

#ifdef TRILOGY_ONLINE_SERVER
			virtual void ServerStartup(const std::u16string_view productKey, const UInt16 port = 7777, const std::chrono::milliseconds& sleepTime = std::chrono::milliseconds{ 1 }) = 0;

			virtual void ServerShutdown() = 0;
#endif
		};
	}
}