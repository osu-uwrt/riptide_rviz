#pragma once
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <ament_index_cpp/get_package_share_directory.hpp>
#include <ament_index_cpp/get_package_prefix.hpp>
#include <rviz_common/panel.hpp>
#include <rviz_common/config.hpp>

#include "ui_ControlPanel.h"
#include <QTimer>

namespace riptide_rviz
{
    class ControlPanel : public rviz_common::Panel
    {
        Q_OBJECT public : ControlPanel(QWidget *parent = 0);
        ~ControlPanel();

        void load(const rviz_common::Config &config) override;
        void save(rviz_common::Config config) const override;

        void onInitialize() override;

    protected Q_SLOTS:
        // QT slots (function callbacks)
        

    protected:
        bool event(QEvent *event);

    private:
        // UI Panel instance
        Ui_ControlPanel *uiPanel;

        rclcpp::Node::SharedPtr clientNode;
        QTimer * spinTimer;
    };

} // namespace riptide_rviz